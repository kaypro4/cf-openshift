<?php

/**
 * @file
 * template.php
 */

function brighton_menu_tree__primary($variables) {
  return '<ul class="nav navbar-nav navbar-right">' . $variables['tree'] . '</ul>';
}

// Remove Height and Width Inline Styles from Drupal Images
function brighton_preprocess_image(&$variables) {
  foreach (array('width', 'height') as $key) {
    unset($variables[$key]);
  }
}

?>