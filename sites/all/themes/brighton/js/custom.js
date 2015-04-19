/**
 * @file
 * A JavaScript file for the theme.
 *
 * In order for this JavaScript to be loaded on pages, see the instructions in
 * the README.txt next to this file.
 */

// JavaScript should be made compatible with libraries other than jQuery by
// wrapping it with an "anonymous closure". See:
// - https://drupal.org/node/1446420
// - http://www.adequatelygood.com/2010/3/JavaScript-Module-Pattern-In-Depth
(function ($, Drupal, window, document, undefined) {



    $(window).load(function() {
      var boxheight = $('#views-bootstrap-carousel-1 .carousel-inner').innerHeight();
      var itemlength = $('#views-bootstrap-carousel-1 .item').length;
      var triggerheight = Math.round(boxheight/itemlength+0.5);
      $('.list-group-item').outerHeight(triggerheight);
      //$("#newsCarousel").carousel('pause');

    });

    $(document).ready(function () {
            var clickEvent = false;

            $('#views-bootstrap-carousel-1').carousel({
                interval:   10000
            }).on('click', '.list-group li', function() {
                    clickEvent = true;
                    $('.list-group li').removeClass('active');
                    $(this).addClass('active');     
            }).on('slid.bs.carousel', function(e) {
                if(!clickEvent) {
                    var count = $('.list-group').children().length -1;
                    var current = $('.list-group li.active');
                    current.removeClass('active').next().addClass('active');
                    var id = parseInt(current.data('slide-to'));
                    if(count == id) {
                        $('.list-group li').first().addClass('active'); 
                    }
                }
                clickEvent = false;
            });

            
            $('.list-group-item').each(function (e) {
                $( this ).attr( "data-slide-to", $(this).index() );
            });

            $( ".list-group-item" ).attr( "data-target", "#views-bootstrap-carousel-1" );


           if ($('.pane-menu-block-1').length == 0) { 
                 $('.left.content-nav').addClass('hidden'); 
                 $('.middle.content-col').removeClass('col-md-7'); 
                 $('.middle.content-col').addClass('col-md-9'); 
                 $('.col-md-10').removeClass('col-md-push-2');     
                 
           }



           $(".pop-it-up-iframe").magnificPopup({
            type:"iframe",
            iframe: {
              markup: '<div style="width:500px; height:600px;">'+
                      '<div class="mfp-iframe-scaler" >'+
                      '<div class="mfp-close"></div>'+
                      '<iframe class="mfp-iframe" frameborder="0" allowfullscreen></iframe>'+
                      '</div></div>'
            }
           });

           $(".overlay").magnificPopup({
            type:"iframe",
            iframe: {
              markup: '<div style="width:500px; height:600px;">'+
                      '<div class="mfp-iframe-scaler" >'+
                      '<div class="mfp-close"></div>'+
                      '<iframe class="mfp-iframe" frameborder="0" allowfullscreen></iframe>'+
                      '</div></div>'
            }
           });

           $('.img-overlay').magnificPopup({ 
            type: 'image'
            // other options
          });
                    
    });
    
    $( window ).resize(function() {
    var boxheight = $('#views-bootstrap-carousel-1 .carousel-inner').innerHeight();
      var itemlength = $('#views-bootstrap-carousel-1 .item').length;
      var triggerheight = Math.round(boxheight/itemlength+0.5);
      $('.list-group-item').outerHeight(triggerheight);
      //$("#newsCarousel").carousel('pause');
    });
    
        

       

       

       

})(jQuery, Drupal, this, this.document);



