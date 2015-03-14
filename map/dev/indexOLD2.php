<?php
error_reporting(E_ALL);
ini_set('display_errors', '1');
include '/var/chroot/home/content/22/10639522/html/map/thumbsup/init.php' 
?>
<!DOCTYPE html>
<head>
<?php echo ThumbsUp::css() ?>
<link rel="stylesheet" href="http://code.jquery.com/mobile/1.3.0/jquery.mobile-1.3.0.min.css" />
<link rel="stylesheet" href="cityfruit.min.css" />
<script src="http://maps.google.com/maps/api/js?sensor=true"></script>
<script type="text/javascript" src="http://www.google.com/jsapi"></script>
<script src="http://code.jquery.com/jquery-1.8.2.min.js"></script>
<script src="http://code.jquery.com/mobile/1.3.0/jquery.mobile-1.3.0.min.js"></script>
<?php echo ThumbsUp::javascript() ?>

<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<meta name="apple-mobile-web-app-capable" content="yes" />
<meta name="viewport" content="initial-scale=1.0,minimum-scale=1.0,maximum-scale=1.0" />
<link rel="Stylesheet" media="all" type="text/css" href="template.css" />

<title>City Fruit Mobile Map</title>

<script type="text/javascript">

//Delay Loading of the Map API until the DOM structure has rendered (but not necessarily all of the images).
document.addEventListener('DOMContentLoaded', function () {
        var element = document.createElement('script');
        element.src = 'http://maps.google.com/maps/api/js?sensor=true&callback=Initialize';
        element.type = 'text/javascript';
        var scripts = document.getElementsByTagName('script')[0];
        scripts.parentNode.insertBefore(element, scripts);
}, false);

//var map,GeoMarker,infoBubble;
google.load('visualization', '1');
	
function Initialize() {

var height = $(window).height();
var width = $(window).width();

$("#map_canvas").height(height);
$("#map_canvas").width(width);
				
 var infoWindow = new google.maps.InfoWindow();
    var MapOptions = {
        zoom: 10,
		center: new google.maps.LatLng(47.608015,-122.33551),
        mapTypeId: google.maps.MapTypeId.ROADMAP,
        sensor: true
    };
	
    map = new google.maps.Map(document.getElementById("map_canvas"), MapOptions);
	
	//Right click anywhere on map to get lat/long.  Useful for adding new tree data.
	google.maps.event.addListener(map, "rightclick", function(event) {
    var lat = event.latLng.lat();
    var lng = event.latLng.lng();
    // populate yor box/field with lat, lng
    alert("Lat=" + lat + "; Lng=" + lng);
	});
	
	var GeoMarker = new GeolocationMarker(map);
	GeoMarker.setCircleOptions({fillColor: '#808080',fillOpacity:'.2'});
	//This will zoom the user to their current location when the map loads.  
	//google.maps.event.addListenerOnce(GeoMarker, 'position_changed', function() {
    //      map.setCenter(this.getPosition());
    //      map.fitBounds(this.getBounds());
    //    });
    google.maps.event.addListener(GeoMarker, 'geolocation_error', function(e) {
       alert('There was an error obtaining your position. Message: ' + e.message);
     });
	 
	 
    GeoMarker.setMap(map);
	
	//sites
	//New way
	//i8flan@gmail.com - 18oQQl1jdoSdhqSJ-re1lLCVoDO_-DXXWVZWo35o, key=AIzaSyAo1C_bwpagv3SWrZmT-Bj_Luh5O6l5bLs
	//info@cityfruit.org - 1fKeuNnvnusctKLMX1T2wPV4AHjoVFdE0_K6Eg3Y, key=AIzaSyAad3BLuHj4GphJ1D9qf9HkxoRzo8-PwR8
	 var query = "SELECT col1, col4, col6, col7 FROM 1fKeuNnvnusctKLMX1T2wPV4AHjoVFdE0_K6Eg3Y";
     query = encodeURIComponent(query);
     var gvizSiteQuery = new google.visualization.Query('http://www.google.com/fusiontables/gvizdata?tq=' + query + '&key=AIzaSyAad3BLuHj4GphJ1D9qf9HkxoRzo8-PwR8');

     var createSiteMarker = function(SiteID, SiteName, coordinate) {
	  var marker = new google.maps.Marker({
		map: map,
		position: coordinate,
		icon: new google.maps.MarkerImage('park.png'),
		zIndex: 2
	  });
          google.maps.event.addListener(marker, 'click', function(event) {
            infoWindow.setPosition(coordinate);
			
			var contentString = [
			'<div style="font-family: sans-serif; font-size:75%">',
			'<b>' + SiteName + '</b> <a href="index.php?ID=' + SiteID + '" target="_blank" title="Link to this site"><img src="images/link.png" /></a> <br /><br />',
			'<a href="http://cityfruit.org/classes/?tag=' + SiteName + '" target="_blank">View upcoming events for this site</a><br /><br />',
			'<a href="signup.php?sitename=' + SiteName + '" data-rel="dialog">Sign up to volunteer</a>',
			'</div>'
			].join('');
			
            infoWindow.setContent(contentString);
            infoWindow.open(map);
			
          });
		  
        };

		gvizSiteQuery.send(function(response) {
        var numRows = response.getDataTable().getNumberOfRows();

          // For each row in the table, create a marker
          for (var i = 0; i < numRows; i++) {
			var lat = response.getDataTable().getValue(i, 2);
            var lng = response.getDataTable().getValue(i, 3);
            var coordinate = new google.maps.LatLng(lat, lng);
            var SiteID = response.getDataTable().getValue(i, 0);
			var SiteName = response.getDataTable().getValue(i, 1);
		
            createSiteMarker(SiteID, SiteName, coordinate);
          }
        });
		
		
	//trees
	//New way
	//i8flan@gmail.com - id=1EbzlO_Ez4u50g6faciaKSF4vM8qjyCCGoLtz5x8, key=AIzaSyAo1C_bwpagv3SWrZmT-Bj_Luh5O6l5bLs
	//info@cityfruit.org - id=1ii6xts-iLOj01BiVRVP5cPRNE7UiYg-xltLMvvk, key=AIzaSyAad3BLuHj4GphJ1D9qf9HkxoRzo8-PwR8
	 var query = "SELECT col0, col1, col2, col3, col4, col5, col6 FROM 1ii6xts-iLOj01BiVRVP5cPRNE7UiYg-xltLMvvk";
     query = encodeURIComponent(query);
     var gvizTreeQuery = new google.visualization.Query('http://www.google.com/fusiontables/gvizdata?tq=' + query + '&key=AIzaSyAad3BLuHj4GphJ1D9qf9HkxoRzo8-PwR8');

     var createTreeMarker = function(coordinate, TreeID, YearPlanted, CommonName, ScientificName) {
	  var marker = new google.maps.Marker({
		map: map,
		position: coordinate,
		icon: new google.maps.MarkerImage('tree.png'),
		zIndex: 1
	  });
          google.maps.event.addListener(marker, 'click', function(event) {
            infoWindow.setPosition(coordinate);
			
			var contentString = [
			'<div style="font-family: sans-serif; font-size:75%; width:220px;">',
			'<b>' + TreeID + '</b> <br /><br />',
			'Common Name: ' + CommonName +  '<br />',
			'Scientific Name: ' + ScientificName +  '<br />',
			'Year Planted: ' + YearPlanted +  '<br /><br />',
			//'<div class="vot_updown1" id="vt_' + TreeID + '"></div>',
			//'<a href="rate.php?ID=' + TreeID + '" data-rel="dialog" id="rate" name="rate">Rate the fruit</a>',
			//'Rate the fruit:',
			'<iframe src="http://cityfruit.org/map/dev/rate.php?ID=' + TreeID + '" width="200" height="125" seamless scrolling="no" frameBorder="0"></iframe>',
			'</div>'
			].join('');
			
			
            infoWindow.setContent(contentString);
            infoWindow.open(map);
			
          });
		  
        };

		
        gvizTreeQuery.send(function(response) {
        var numRows = response.getDataTable().getNumberOfRows();

          // For each row in the table, create a marker
          for (var i = 0; i < numRows; i++) {
            var lat = response.getDataTable().getValue(i, 1);
            var lng = response.getDataTable().getValue(i, 2);
            var coordinate = new google.maps.LatLng(lat, lng);
            var TreeID = response.getDataTable().getValue(i, 0);
			var YearPlanted = response.getDataTable().getValue(i, 3);
			var ScientificName = response.getDataTable().getValue(i, 4);
			var CommonName = response.getDataTable().getValue(i, 5);
            //var delivery = response.getDataTable().getValue(i, 2);

            createTreeMarker(coordinate, TreeID, YearPlanted, CommonName, ScientificName);
          }
        });
		

	//check to see if there is an ID in the URL. If so, then zoom to the location on load (used for QR codes)
	var id_value = getQuerystring('ID');
	if(id_value != "") {
		<?php
		$data = file_get_contents('https://www.googleapis.com/fusiontables/v1/query?sql=SELECT%20col1,%20col4,%20col6,%20col7%20FROM%201fKeuNnvnusctKLMX1T2wPV4AHjoVFdE0_K6Eg3Y&key=AIzaSyAad3BLuHj4GphJ1D9qf9HkxoRzo8-PwR8&alt=csv');
		$rows = explode("\n", $data);
		for($i = 1; $i < count($rows)-1; $i++)
		{
			$temp = explode(',', $rows[$i]);
			$siteid = $temp[0];
			$lat = $temp[2];
			$long = $temp[3];
			echo "if (id_value == $siteid){";
			echo "map.setOptions({";
			echo "center: new google.maps.LatLng($lat,$long),";
			echo "zoom: 17";
			echo "});";
			echo "}";
		}
		?>

			
		}	
	
}

	
function getQuerystring(key, default_)
{
  if (default_==null) default_=""; 
  key = key.replace(/[\[]/,"\\\[").replace(/[\]]/,"\\\]");
  var regex = new RegExp("[\\?&]"+key+"=([^&#]*)");
  var qs = regex.exec(window.location.href);
  if(qs == null)
    return default_;
  else
    return qs[1];
}

function resetMap() {
    // retrieve new selection
    var latlongChoice = document.getElementById("placeSelect").value;
	if (latlongChoice!=0) {

		// separate into lat and long
		var latlongParts = latlongChoice.split(",");
		var newPos = new google.maps.LatLng(latlongParts[0], latlongParts[1]);

		map.setOptions({
			center: newPos,
			zoom: 17
		});
	}
		//may deal with missing tiles in map after dialog box loads.  Verify on iphone/android.
		//setTimeout(function() {
        //    google.maps.event.trigger(map,'resize');
        //}, 500);

} //end initialize
google.maps.event.addDomListener(window, 'load', Initialize);
$('#map').live('pagebeforeshow',function(e,data){
    $('#map_canvas').height($(window).height() - (10 + $('[data-role=header]').height() - $('[data-role=footer]').height()));
	google.maps.event.trigger(map, 'resize');
});
</script>
</head>
<body>


	<div data-role="page" data-theme="a">
        <div data-role="header" data-theme="a">
            <img src="cflogo.jpg" style="padding:2px 0px 2px 2px">
			
			<a href="index.php" rel="external" class="ui-btn-right" data-icon="refresh" data-iconpos="notext" data-direction="reverse">Refresh</a> 
        </div>
        <div data-role="content">
			 <div id="map_canvas"></div>  
			 
			<div style="position: absolute; bottom: 35px; right: 5px;" id="sitemenu">
				<select id="placeSelect" name="placeSelect" onchange="resetMap()" data-native-menu="false">
				<option value="0">Zoom to a steward site</option>
				<?php
				//use the data that we pulled above for the steward sites to render the select box to zoom to
				$rows = explode("\n", $data);
				for($i = 1; $i < count($rows)-1; $i++)
				{
					$temp = explode(',', $rows[$i]);
					$siteid = $temp[0];
					$sitename = $temp[1];
					$lat = $temp[2];
					$long = $temp[3];
					echo "<option value='$lat,$long'>$sitename</option>";
				}
				//echo print_r($sitedata);  
				?>
				</select>
				
			</div>
		 
        </div>
        <div data-role="footer" data-position="fixed" data-theme="a">
			<a href="http://www.cityfruit.org/" rel="external" data-icon="home" data-iconpos="notext">City Fruit Home</a> 
			<a href="about.htm" data-rel="dialog" class="ui-btn-right" data-icon="info" data-iconpos="notext" data-transition="flip">About</a> 
        </div>
		
    </div>

<script src="https://google-maps-utility-library-v3.googlecode.com/svn/trunk/geolocationmarker/src/geolocationmarker-compiled.js"></script>

</body>

</html>