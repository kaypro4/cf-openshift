<?php
/**
 * @file
 * main_site_feature.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function main_site_feature_taxonomy_default_vocabularies() {
  return array(
    'calendar_event_category' => array(
      'name' => 'Calendar Event Category',
      'machine_name' => 'calendar_event_category',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'faq_category' => array(
      'name' => 'FAQ Category',
      'machine_name' => 'faq_category',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'tags' => array(
      'name' => 'Tags',
      'machine_name' => 'tags',
      'description' => 'Use tags to group articles on similar topics into categories.',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
