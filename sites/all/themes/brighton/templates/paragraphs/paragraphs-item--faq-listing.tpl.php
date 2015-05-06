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

<h2><?php print $content['field_faq_title'][0]['#markup'] ?></h2>
<?php
  $my_arg = '';
  $count = count($content['field_faq_categories']['#items']);
  for ($x = 0; $x < $count; $x++) {
    $my_arg .= $content['field_faq_categories']['#items'][$x]['tid'] . ",";
  }
  $my_arg = rtrim($my_arg, ',');
  //print $my_arg;
  print views_embed_view('faq_listing', 'faq_listing', $my_arg);
?>


<?php
//dpm($content);
?>
