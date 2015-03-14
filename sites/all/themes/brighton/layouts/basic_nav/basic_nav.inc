<?php

/**
 * implementation of hook_panels_layouts()
 */
// Plugin definition
$plugin = array(
  'title' => t('Basic Page w Auto nav'),
  'category' => t('OTO'),
  'icon' => 'basic_nav.png',
  'theme' => 'basic-nav',
  'css' => 'basic_nav.css',
  'regions' => array(
    'nav' => t('Nav'),
    'content' => t('Content'),
  ),
);
