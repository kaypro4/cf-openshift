<?php
/**
 * @file
 * main_site_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function main_site_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "file_entity" && $api == "file_default_displays") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "password_policy" && $api == "default_password_policy") {
    return array("version" => "1");
  }
  if ($module == "password_policy" && $api == "default_password_policy_role") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function main_site_feature_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function main_site_feature_image_default_styles() {
  $styles = array();

  // Exported image style: banner_image.
  $styles['banner_image'] = array(
    'label' => 'Banner Image',
    'effects' => array(
      5 => array(
        'name' => 'manualcrop_crop_and_scale',
        'data' => array(
          'width' => 831,
          'height' => 360,
          'upscale' => 0,
          'respectminimum' => 1,
          'onlyscaleifcrop' => 0,
          'style_name' => 'banner_image',
        ),
        'weight' => 0,
      ),
      6 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 831,
          'height' => 360,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: feature_image.
  $styles['feature_image'] = array(
    'label' => 'Feature Image',
    'effects' => array(
      1 => array(
        'name' => 'manualcrop_crop',
        'data' => array(
          'width' => 680,
          'height' => 680,
          'keepproportions' => 1,
          'style_name' => 'feature_image',
        ),
        'weight' => 0,
      ),
      2 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 680,
          'height' => 680,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: profile_image.
  $styles['profile_image'] = array(
    'label' => 'Profile Image',
    'effects' => array(
      3 => array(
        'name' => 'manualcrop_crop',
        'data' => array(
          'width' => 100,
          'height' => 129,
          'keepproportions' => 1,
          'style_name' => 'profile_image',
        ),
        'weight' => 0,
      ),
      4 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 100,
          'height' => 129,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: slideshow_4_3.
  $styles['slideshow_4_3'] = array(
    'label' => 'Slideshow 4:3',
    'effects' => array(
      5 => array(
        'name' => 'manualcrop_crop',
        'data' => array(
          'width' => 831,
          'height' => 623,
          'keepproportions' => 1,
          'style_name' => 'slideshow_4_3',
        ),
        'weight' => 0,
      ),
      6 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 831,
          'height' => 623,
        ),
        'weight' => 2,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function main_site_feature_node_info() {
  $items = array(
    'article' => array(
      'name' => t('Blog'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'event' => array(
      'name' => t('Event'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'faq_item' => array(
      'name' => t('FAQ Item'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Question'),
      'help' => '',
    ),
    'fresh_sheet' => array(
      'name' => t('Fresh Sheet'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'orchard' => array(
      'name' => t('Orchard'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'page' => array(
      'name' => t('Basic page'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'webform' => array(
      'name' => t('Webform'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

/**
 * Implements hook_paragraphs_info().
 */
function main_site_feature_paragraphs_info() {
  $items = array(
    'banner_image' => array(
      'name' => 'Banner Image',
      'bundle' => 'banner_image',
      'locked' => '1',
    ),
    'block' => array(
      'name' => 'View Block (Experts Only)',
      'bundle' => 'block',
      'locked' => '1',
    ),
    'call_to_action' => array(
      'name' => 'Call To Action',
      'bundle' => 'call_to_action',
      'locked' => '1',
    ),
    'faq_listing' => array(
      'name' => 'FAQ Listing',
      'bundle' => 'faq_listing',
      'locked' => '1',
    ),
    'feature_block' => array(
      'name' => 'Feature Block',
      'bundle' => 'feature_block',
      'locked' => '1',
    ),
    'full_width_text' => array(
      'name' => 'Full Width Text',
      'bundle' => 'full_width_text',
      'locked' => '1',
    ),
    'google_map' => array(
      'name' => 'Google Map',
      'bundle' => 'google_map',
      'locked' => '1',
    ),
    'quote' => array(
      'name' => 'Quote',
      'bundle' => 'quote',
      'locked' => '1',
    ),
    'slideshow' => array(
      'name' => 'Slideshow',
      'bundle' => 'slideshow',
      'locked' => '1',
    ),
    'upcoming_events_listing' => array(
      'name' => 'Upcoming Events Listing',
      'bundle' => 'upcoming_events_listing',
      'locked' => '1',
    ),
    'video' => array(
      'name' => 'Video',
      'bundle' => 'video',
      'locked' => '1',
    ),
    'webform' => array(
      'name' => 'Webform',
      'bundle' => 'webform',
      'locked' => '1',
    ),
  );
  return $items;
}
