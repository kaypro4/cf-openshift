<?php

/**
 * implementation of hook_panels_layouts()
 */
// Plugin definition
$plugin = array(
  'title' => t('Right Col Menu 2'),
  'category' => t('WSCC - Audience'),
  'icon' => 'right_col_menu2.png',
  'theme' => 'right_col_menu2',
  'css' => 'right_col_menu2.css',
  'regions' => array(
    'header' => t('Content header'),
    'header_find_it_widget' => t('Header FI Widget'),
    'marketing_message' => t('Marketing Message'),
    'services' => t('Services'),
    'main_col_full' => t('Main Column Full'),
    'main_col' => t('Main Column'),
    'main_col_full_footer' => t('Main Column Full Footer'),
    'menu' => t('Menu'),
  ),
);
