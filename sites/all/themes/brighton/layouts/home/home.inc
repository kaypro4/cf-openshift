<?php

/**
 * implementation of hook_panels_layouts()
 */
// Plugin definition
$plugin = array(
  'title' => t('Home'),
  'category' => t('CF'),
  'icon' => 'home.png',
  'theme' => 'home',
  'css' => 'home.css',
  'regions' => array(
    'first' => t('Slideshow'),
    'second' => t('Intro'),
    'third' => t('Latest'),
    'fourth' => t('Social'),

  ),
);
