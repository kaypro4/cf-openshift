<?php

/**
 * @file
 * Default theme implementation for a single paragraph item.
 *
 * Available variables:
 * - $content: An array of content items. Use render($content) to print them all, or
 *   print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. By default the following classes are available, where
 *   the parts enclosed by {} are replaced by the appropriate values:
 *   - entity
 *   - entity-paragraphs-item
 *   - paragraphs-item-{bundle}
 *
 * Other variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 *
 * @see template_preprocess()
 * @see template_preprocess_entity()
 * @see template_process()
 */
?>


<div id="container" class="box-shadow">
<div class="row">
    
        <div class="lib-panel">
                <div class="col-xs-4 feature-img">
                	<?php print render($content['field_feature_image']); ?>
                </div>
                <div class="col-xs-7">
                    <div class="lib-row lib-header">
                        <h3><?php print render($content['field_feature_title'][0]['#markup']); ?></h3>
                        <div class="lib-header-seperator"></div>
                    </div>
                    <div class="lib-row lib-desc">
                        <?php print render($content['field_feature_text'][0]['#markup']); ?>
                    </div>
                    <?php if (isset($content['field_feature_link'][0]['#element']['url'])) { ?>
                    <a style="float:right; padding-top:10px; margin-right:20px;" href="<?php print render($content['field_feature_link'][0]['#element']['url']); ?> "><?php print render($content['field_feature_link'][0]['#element']['title']); ?>  <i class="fa fa-arrow-right"></i></a>
                	<?php } ?>
                </div>
                <div class="col-xs-1">
                	
                </div>

        </div>
    
</div>
</div>

	<?php  
	//dpm($content); 
	?>
        
       
     

