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


<div id="container">
<div class="row">
    
        <div class="lib-panel">
                <div class="col-xs-4 feature-img text-center" style="border: 1px solid gray;">
                	<h1 id="counter-<?php print render($content['field_total_count']['#object']->item_id); ?>"><?php print render($content['field_total_count'][0]['#markup']); ?> <?php print render($content['field_append_text'][0]['#markup']); ?></h1> 
                	<br />
                	<?php print render($content['field_text_below_number'][0]['#markup']); ?>
                	
                </div>
                <div class="col-xs-8">
                    <div class="lib-row lib-desc">
                        <?php print render($content['field_full_text'][0]['#markup']); ?>
                    </div>


                </div>

        </div>
    
</div>
</div>

	<?php  
	//dpm($content); 
	?>
        
       
     

