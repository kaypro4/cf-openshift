<?php
/**
 * @file
 * main_site_feature.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function main_site_feature_filter_default_formats() {
  $formats = array();

  // Exported format: Full HTML.
  $formats['full_html'] = array(
    'format' => 'full_html',
    'name' => 'Full HTML',
    'cache' => 1,
    'status' => 1,
    'weight' => 1,
    'filters' => array(
      'filter_url' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(
          'filter_url_length' => 72,
        ),
      ),
      'shortcode' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(
          'alert' => 0,
          'badge' => 0,
          'breadcrumb' => 0,
          'breadcrumb-item' => 0,
          'button' => 1,
          'button-group' => 0,
          'button-toolbar' => 0,
          'caret' => 0,
          'carousel' => 0,
          'carousel-item' => 0,
          'code' => 0,
          'collapse' => 1,
          'collapsibles' => 1,
          'column' => 1,
          'container' => 0,
          'divider' => 0,
          'dropdown' => 0,
          'dropdown-header' => 0,
          'dropdown-item' => 0,
          'emphasis' => 0,
          'icon' => 1,
          'img' => 0,
          'jumbotron' => 0,
          'label' => 0,
          'lead' => 0,
          'list-group' => 0,
          'list-group-item' => 0,
          'list-group-item-heading' => 0,
          'list-group-item-text' => 0,
          'media' => 0,
          'media-body' => 0,
          'media-object' => 0,
          'modal' => 1,
          'modal-footer' => 0,
          'nav' => 0,
          'nav-item' => 0,
          'page-header' => 0,
          'panel' => 1,
          'popover' => 0,
          'progress' => 0,
          'progress-bar' => 0,
          'responsive' => 0,
          'row' => 1,
          'span' => 0,
          'tab' => 1,
          'table' => 1,
          'table-wrap' => 0,
          'tabs' => 1,
          'thumbnail' => 0,
          'tooltip' => 0,
          'well' => 0,
          'shortcode-help' => 0,
        ),
      ),
      'shortcode_text_corrector' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(),
      ),
    ),
  );

  return $formats;
}
