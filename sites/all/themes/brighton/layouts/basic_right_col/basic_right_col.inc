<?php

/**
 * implementation of hook_panels_layouts()
 */
// Plugin definition
$plugin = array(
  'title' => t('Basic Page w Right Column'),
  'category' => t('CF'),
  'icon' => 'basic_right_col.png',
  'theme' => 'basic-right-col',
  'css' => 'basic_right_col.css',
  'regions' => array(
  	'title' => t('Title'),
    'nav' => t('Nav'),
    'content' => t('Content'),
    'right' => t('Right'),
  ),
);
