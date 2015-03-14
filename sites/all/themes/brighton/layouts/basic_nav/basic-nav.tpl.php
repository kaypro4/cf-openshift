<?php
//'header'
//'blocks'
//'content'
?>



    <div class="container">
      <div class="row">

        <div class="col-sm-2 nav-col">
          <?php print $content['nav']; ?>
        </div>

        <div class="col col-sm-10 content-col">
          <?php print $content['content']; ?>
        </div>

      </div>
    </div>
