/**
 * @file
 * Webform module Gmap page script.
 */

var limit_count = {};
var markers = {};

(function ($) {
  Drupal.behaviors.gmapPage = {
    attach: function(context, settings) {
      function initialize() {
        $('.gmap-field').each(function(index, Element) {
          var cid = $(Element).attr('data-cid');
          var lat = '47.6097';
          var lon = '122.3331';
          var zoom = '10';
          var icon = '';
          var limit = '1';
          var latlng = new google.maps.LatLng(lat, lon);
          limit_count['gmap-' + cid] = 1;
          var myOptions = {
            zoom: parseInt(zoom),
            center: latlng,
            mapTypeId: google.maps.MapTypeId.ROADMAP
          };
          var map = new google.maps.Map(Element, myOptions);
          var input = $(Element).next('.form-item').find('.field-type-places-autocomplete')[0];
          var autocomplete = new google.maps.places.Autocomplete(input);
          autocomplete.bindTo('bounds', map);

          google.maps.event.addListener(autocomplete, 'place_changed', function(event) {
            var place = autocomplete.getPlace();
            if (place.geometry.viewport) {
              map.fitBounds(place.geometry.viewport);
            } else {
              map.setCenter(place.geometry.location);
              map.setZoom(7);
            }
            var address = '';
            if (place.address_components) {
              address = [
                (place.address_components[0] && place.address_components[0].short_name || ''),
                (place.address_components[1] && place.address_components[1].short_name || ''),
                (place.address_components[2] && place.address_components[2].short_name || '')
              ].join(' ');
            }
            if((parseInt(limit) < parseInt(limit_count['gmap-' + cid])) && parseInt(limit) != 0) {
              return false;
            }
            placeMarker(place.geometry.location, map, cid, icon, limit_count);
          });
          google.maps.event.addListener(map, 'click', function(e) {
            if((parseInt(limit) < parseInt(limit_count['gmap-' + cid])) && parseInt(limit) != 0) {
              return false;
            }
            placeMarker(e.latLng, map,cid, icon);
          });
          google.maps.event.addListener(map, 'zoom_changed', function() {
            document.getElementById('gmap-zoom-' + cid).value = map.getZoom();
          });
        });
      }
      function placeMarker(position, map, cid, icon) {
        var marker = new google.maps.Marker({
          position: position,
          map: map,
          icon: icon
        });
        var id = parseInt(limit_count['gmap-' + cid]) + 1;
        markers[id] = marker;
        document.getElementById('gmap-lat-' + cid).value = document.getElementById('gmap-lat-' + cid).value + position.lat() + ',';
        document.getElementById('gmap-lon-' + cid).value = document.getElementById('gmap-lon-' + cid).value + position.lng() + ',';
        map.panTo(position);
        limit_count['gmap-' + cid] = parseInt(limit_count['gmap-' + cid]) + 1;

        google.maps.event.addListener(marker, "click", function(point){ delMarker(id, cid) });
      }

      var delMarker = function(id,cid) {
        marker = markers[id];

        var lat = marker.position.lat();
        var lng = marker.position.lng();
        document.getElementById('gmap-lat-' + cid).value = document.getElementById('gmap-lat-' + cid).value.replace(lat + ",","");
        document.getElementById('gmap-lon-' + cid).value = document.getElementById('gmap-lon-' + cid).value.replace(lng + ",","");
        marker.setMap(null);
        limit_count['gmap-' + cid]  = parseInt(limit_count['gmap-' + cid]) - 1;
      }
      google.maps.event.addDomListener(window, 'load', initialize);
    }
  };
})(jQuery);
