<?php

/**
 * implementation of hook_panels_layouts()
 */
// Plugin definition
$plugin = array(
  'title' => t('Basic Page No Right Column'),
  'category' => t('CF'),
  'icon' => 'basic_no_right_col.png',
  'theme' => 'basic-no-right-col',
  'css' => 'basic_no_right_col.css',
  'regions' => array(
  	'title' => t('Title'),
    'nav' => t('Nav'),
    'content' => t('Content'),
  ),
);
