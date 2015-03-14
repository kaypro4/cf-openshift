<?php
//'header'
//'blocks'
//'content'
?>

<div class="panel-page clearfix home-page-panel">

  <div class="blocks-panel-wrapper">
    <div class="container">
      <div class="row">
        <?php print $content['first']; ?>
      </div>
    </div>
  </div>


  <div class="content-panel-wrapper features">
    <div class="container">
      <div class="row">
        <?php print $content['second']; ?>
      </div>
    </div>
  </div>

    <div class="content-panel-wrapper latest">
    <div class="container">
      <div class="row">
        <?php print $content['third']; ?>
      </div>
    </div>
  </div>


    <div class="content-panel-wrapper">
    <div class="container">
      <div class="row">
        <?php print $content['fourth']; ?>
      </div>
    </div>
  </div>

</div>
