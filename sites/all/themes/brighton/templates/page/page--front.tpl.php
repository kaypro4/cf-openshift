<?php
/**
 * @file
 * Default theme implementation to display a single Drupal page.
 *
 * The doctype, html, head and body tags are not in this template. Instead they
 * can be found in the html.tpl.php template in this directory.
 *
 * Available variables:
 *
 * General utility variables:
 * - $base_path: The base URL path of the Drupal installation. At the very
 *   least, this will always default to /.
 * - $directory: The directory the template is located in, e.g. modules/system
 *   or themes/bartik.
 * - $is_front: TRUE if the current page is the front page.
 * - $logged_in: TRUE if the user is registered and signed in.
 * - $is_admin: TRUE if the user has permission to access administration pages.
 *
 * Site identity:
 * - $front_page: The URL of the front page. Use this instead of $base_path,
 *   when linking to the front page. This includes the language domain or
 *   prefix.
 * - $logo: The path to the logo image, as defined in theme configuration.
 * - $site_name: The name of the site, empty when display has been disabled
 *   in theme settings.
 * - $site_slogan: The slogan of the site, empty when display has been disabled
 *   in theme settings.
 *
 * Navigation:
 * - $main_menu (array): An array containing the Main menu links for the
 *   site, if they have been configured.
 * - $secondary_menu (array): An array containing the Secondary menu links for
 *   the site, if they have been configured.
 * - $breadcrumb: The breadcrumb trail for the current page.
 *
 * Page content (in order of occurrence in the default page.tpl.php):
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title: The page title, for use in the actual HTML content.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 * - $messages: HTML for status and error messages. Should be displayed
 *   prominently.
 * - $tabs (array): Tabs linking to any sub-pages beneath the current page
 *   (e.g., the view and edit tabs when displaying a node).
 * - $action_links (array): Actions local to the page, such as 'Add menu' on the
 *   menu administration interface.
 * - $feed_icons: A string of all feed icons for the current page.
 * - $node: The node object, if there is an automatically-loaded node
 *   associated with the page, and the node ID is the second argument
 *   in the page's path (e.g. node/12345 and node/12345/revisions, but not
 *   comment/reply/12345).
 *
 * Regions:
 * - $page['help']: Dynamic help text, mostly for admin pages.
 * - $page['highlighted']: Items for the highlighted content region.
 * - $page['content']: The main content of the current page.
 * - $page['sidebar_first']: Items for the first sidebar.
 * - $page['sidebar_second']: Items for the second sidebar.
 * - $page['header']: Items for the header region.
 * - $page['footer']: Items for the footer region.
 *
 * @see bootstrap_preprocess_page()
 * @see template_preprocess()
 * @see template_preprocess_page()
 * @see bootstrap_process_page()
 * @see template_process()
 * @see html.tpl.php
 *
 * @ingroup themeable
 */
?>


<div class="navbar navbar-inverse" >
    <div class="container">
    
        <div class="navbar-header">
            <button type="button" class="navbar-toggle" data-toggle="collapse" data-target=".navbar-collapse">
                <span class="icon-bar"></span>
                <span class="icon-bar"></span>
                <span class="icon-bar"></span>
            </button>
            <?php if ($logo): ?>
            <a class="logo navbar-btn pull-left" href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>">
              <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" />
            </a>
            <?php endif; ?>
        </div>

      <?php if (!empty($primary_nav) || !empty($secondary_nav) || !empty($page['navigation'])): ?>
        <div class="navbar-collapse collapse">
          <nav role="navigation">
            <?php if (!empty($primary_nav)): ?>
              <?php print render($primary_nav); ?>
            <?php endif; ?>


          </nav>
        </div>
      <?php endif; ?>
  
    </div>
</div>
<!--/.NAVBAR END-->

<div class="main-container container">

  <div class="row">

      <?php print $messages; ?>
      
  </div>
</div>

<?php print render($page['content']); ?>


 <section id="footer">  
        <div class="container">
       <div class="row  pad-bottom" >
          <div class="col-md-2">
          <img src="/sites/all/themes/brighton/logo.png" height="35px" style="margin-bottom:15px; margin-top: 4px;" class="logo-footer">
                        <p>
                           <a href="mailto:info@cityfruit.org">info@cityfruit.org</a><br />
                           (360) 602-1778 <br />
                           2524 16th Ave S #301 <br />Seattle, WA 98144  <br />
                        </p>
                <a href="mailto:info@cityfruit.org" class="btn btn-primary btn-sm" >Send us a message</a>
            </div>
            
           <div class="col-md-7">
            <h4> <strong>ABOUT</strong> </h4>
                        <p>
                           City Fruit is a non-profit corporation with a tax exempt status (501c[3]), supported by donations, memberships, class fees, sales and grants. Show your support by <a href="/donate">joining today</a>.
                        </p>
            <a href="/about-us" >More about us</a>
            </div>
            
           <div class="col-md-3">
                <h4> <strong>CONNECT WITH US</strong> </h4>
                <p>
                 <a href="https://www.facebook.com/cityfruit" target="_blank"><i class="fa fa-facebook-square fa-3x"  ></i></a>  
                 <a href="https://twitter.com/cityfruit" target="_blank"><i class="fa fa-twitter-square fa-3x"  ></i></a>  
                  <a href="https://instagram.com/cityfruitseattle" target="_blank"><i class="fa fa-instagram fa-3x"  ></i></a>  
                 
               </p>
            </div>
            
          
           </div>
        </div>
</section>     

<div class="container">
<?php if (!empty($secondary_nav)): ?>
  <?php print render($secondary_nav); ?>
<?php endif; ?>

<?php if (!empty($page['navigation'])): ?>
  <?php print render($page['navigation']); ?>
<?php endif; ?>
  <?php print render($page['footer']); ?>
</div>

<!-- Modal -->
<div id="newsletterSignup" class="modal fade" role="dialog">
  <div class="modal-dialog">

    <!-- Modal content-->
    <div class="modal-content">
      <div class="modal-header" style="border-bottom:none;">
        <button type="button" class="close" data-dismiss="modal" style="padding-bottom: 5px;">&times;</button>
      </div>
      <div class="modal-body">
        
        <!-- Begin MailChimp Signup Form -->
        <link href="//cdn-images.mailchimp.com/embedcode/classic-081711.css" rel="stylesheet" type="text/css">
        <style type="text/css">
          #mc_embed_signup{background:#fff; clear:left; font:14px Helvetica,Arial,sans-serif; }
          /* Add your own MailChimp form style overrides in your site stylesheet or in this style block.
             We recommend moving this block and the preceding CSS link to the HEAD of your HTML file. */
        </style>
        <div id="mc_embed_signup">

        <form action="//cityfruit.us8.list-manage.com/subscribe/post?u=8bd71ceab5deaa81c64a330f9&amp;id=7855db3894" method="post" id="mc-embedded-subscribe-form" name="mc-embedded-subscribe-form" class="validate" target="_blank" novalidate>
        <p>Sign up for our monthly newsletter and/or topic interest mailings.</p>
            <div id="mc_embed_signup_scroll">
        <div class="indicates-required"><span class="asterisk">*</span> indicates required</div>
        <div class="mc-field-group">
          <label for="mce-EMAIL">Email Address  <span class="asterisk">*</span>
        </label>
          <input type="email" value="" name="EMAIL" class="required email" id="mce-EMAIL">
        </div>
        <div class="mc-field-group">
          <label for="mce-FNAME">First Name  <span class="asterisk">*</span>
        </label>
          <input type="text" value="" name="FNAME" class="required" id="mce-FNAME">
        </div>
        <div class="mc-field-group">
          <label for="mce-LNAME">Last Name  <span class="asterisk">*</span>
        </label>
          <input type="text" value="" name="LNAME" class="required" id="mce-LNAME">
        </div>
        <div class="mc-field-group input-group">
            <strong>Interests </strong>
            <ul><li><input type="checkbox" value="2" name="group[18373][2]" id="mce-group[18373]-18373-0" checked><label for="mce-group[18373]-18373-0">Monthly Newsletter</label></li>
        <li><input type="checkbox" value="4" name="group[18373][4]" id="mce-group[18373]-18373-1"><label for="mce-group[18373]-18373-1">Volunteering</label></li>
        <li><input type="checkbox" value="8" name="group[18373][8]" id="mce-group[18373]-18373-2"><label for="mce-group[18373]-18373-2">Tree Owner</label></li>
        </ul>
        </div>
          <div id="mce-responses" class="clear">
            <div class="response" id="mce-error-response" style="display:none"></div>
            <div class="response" id="mce-success-response" style="display:none"></div>
          </div>    <!-- real people should not fill this in and expect good things - do not remove this or risk form bot signups-->
            <div style="position: absolute; left: -5000px;"><input type="text" name="b_8bd71ceab5deaa81c64a330f9_7855db3894" tabindex="-1" value=""></div>
            <div class="clear"><input type="submit" value="Subscribe" name="subscribe" id="mc-embedded-subscribe" class="button"></div>
            </div>
        </form>
        </div>
        <script type='text/javascript' src='//s3.amazonaws.com/downloads.mailchimp.com/js/mc-validate.js'></script><script type='text/javascript'>(function($) {window.fnames = new Array(); window.ftypes = new Array();fnames[0]='EMAIL';ftypes[0]='email';fnames[1]='FNAME';ftypes[1]='text';fnames[2]='LNAME';ftypes[2]='text';}(jQuery));var $mcj = jQuery.noConflict(true);</script>
        <!--End mc_embed_signup-->

      </div>
    </div>

  </div>
</div>