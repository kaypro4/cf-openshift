<?php
$top_content_classes = 'top-content';
if (!empty($content['services'])) {
  $top_content_classes .= ' services-full';
}
?>
<div class="panel-page clearfix">
  <div class="<?php print $top_content_classes; ?>">
    <?php print $content['header']; ?>

    <?php print $content['marketing_message']; ?>

    <div id="fi-widget">
      <div class="container">
        <div class="row">
          <div class="col-md-7 col-md-offset-17">
            <div class="content"<?php print $content_attributes; ?>>
              <?php print $content['header_find_it_widget']; ?>
            </div>
          </div>
        </div>
      </div>
    </div>

    <?php if (!empty($content['services'])): ?>
    <div class="container">
      <div class="row">
        <div class="col-md-offset-1 col-md-22">
          <?php print $content['services']; ?>
        </div>
      </div>
    </div>
    <?php endif; ?>

  </div>

  <div class="container">
    <div class="row">
      <div class="col-md-offset-1 col-md-22">
        <?php print $content['main_col_full']; ?>
      </div>
    </div>

    <div class="row main-col">
      <div class="col-md-offset-1 col-md-7 col-md-push-15 menu-col">

        <button type="button" class="btn hidden-md hidden-lg" data-toggle="collapse" data-target="#right-col-menu-collapse" id="right-col-menu-collapse-button">
          Navigate <i class="fa fa-bars"></i>
        </button>
        <div class="menu-col-content collapse in" id="right-col-menu-collapse">
          <?php print $content['menu']; ?>
        </div>
      </div>
      <div class="col-md-offset-1 col-md-14 col-md-pull-8">
        <div class="row">
          <?php print $content['main_col']; ?>
        </div>
      </div>
    </div>

    <div class="row main-col-footer">
      <div class="col-md-offset-1 col-md-22">
        <?php print $content['main_col_full_footer']; ?>
      </div>
    </div>

  </div>
</div>
