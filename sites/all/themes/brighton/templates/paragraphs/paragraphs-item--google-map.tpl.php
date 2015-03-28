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


<iframe width="<?php print render($content['field_map_width'][0]['#markup']); ?>" height="<?php print render($content['field_map_height'][0]['#markup']); ?>" frameborder="0" style="border:0" src="https://www.google.com/maps/embed/v1/place?q=<?php print urlencode(render($content['field_place_name'][0]['#markup'])); ?>&key=<?php print render($content['field_google_api_key'][0]['#markup']); ?>"></iframe>

    
  		<?php  
 		//dpm($content); 
  		?>
        
       
     

