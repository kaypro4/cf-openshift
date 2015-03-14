<?php

/**
 * implementation of hook_panels_layouts()
 */
// Plugin definition
$plugin = array(
  'title' => t('Basic Page'),
  'category' => t('OTO'),
  'icon' => 'basic.png',
  'theme' => 'basic',
  'css' => 'basic.css',
  'regions' => array(
    //'nav' => t('Nav'),
    'content' => t('Content'),
  ),
);
