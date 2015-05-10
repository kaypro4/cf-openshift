<?php
//'header'
//'blocks'
//'content'
?>



<div class="row">
   <div class="col-md-12">
	   <?php print $content['title']; ?>
  </div>
</div>
<div class="row">

  <div class="col-md-9 middle content-col">
    <?php print $content['content']; ?>
  </div>

  <div class="col-md-3 right right-col">
    <?php print $content['right']; ?>
  </div>

</div>
