<?php
//'header'
//'blocks'
//'content'
?>





<div class="row">
   <div class="col-md-10 col-md-push-2">
	   <?php print $content['title']; ?>
  </div>
</div>
<div class="row">

  <div class="col-md-2 left content-nav">
    <?php print $content['nav']; ?>
  </div>

  <div class="col-md-7 middle content-col">
    <?php print $content['content']; ?>
  </div>

  <div class="col-md-3 right right-col">
    <?php print $content['right']; ?>
  </div>

</div>
