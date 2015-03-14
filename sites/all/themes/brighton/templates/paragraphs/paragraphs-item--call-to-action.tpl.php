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

    
    
    
     <span class="stripe cta-top"></span>

		<div class="row call-to-action">
		
		
		  <div class="col-sm-9 col-xs-12">
		    <span class="vert-mid"><p><?php print render($content['field_action_text'][0]['#markup']); ?></p></span>
		  </div>

		  <div class="col-sm-3 col-xs-12">
		     <a class="btn btn-sm btn-danger inline-cta" href="<?php print render($content['field_action_link_new'][0]['#markup']); ?>"><?php print render($content['field_action_link_text'][0]['#markup']); ?> <i class="fa fa-share"></i></a>
		  </div>
		  
		  
		</div>

	<span class="stripe cta-bottom"></span>
		
    
    
    
  		<?php  
 		//dpm($content); 
  		?>
        
       
     

