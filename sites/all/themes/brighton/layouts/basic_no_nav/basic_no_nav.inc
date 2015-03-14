<?php

/**
 * implementation of hook_panels_layouts()
 */
// Plugin definition
$plugin = array(
  'title' => t('Basic Page w No Left Nav'),
  'category' => t('CF'),
  'icon' => 'basic_no_nav.png',
  'theme' => 'basic-no-nav',
  'css' => 'basic_no_nav.css',
  'regions' => array(
  	'title' => t('Title'),
    'content' => t('Content'),
    'right' => t('Right'),
  ),
);
