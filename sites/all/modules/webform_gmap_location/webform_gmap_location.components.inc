<?php

/**
 * @file
 * Webform module Gmap component.
 */

define('GMAP_DEFAULT_LAT', 48.00);
define('GMAP_DEFAULT_LON', 37.80);
define('GMAP_DEFAULT_ZOOM', 10);
define('GMAP_DEFAULT_LIMIT', 1);

/**
 * Implements _webform_defaults_component().
 */
function _webform_defaults_gmap() {
  return array(
    'name'      => '',
    'form_key'  => NULL,
    'required'  => 0,
    'mandatory' => 0,
    'pid'       => 0,
    'weight'    => 0,
    'extra'     => array(
      'title_display'              => 0,
      'private'                    => FALSE,
      'attributes'                 => array(),
      'width'                      => 600,
      'height'                     => 300,
      'marker'                     => 0,
      'gmap'                       => '',
      'location'                   => '',
      'gmap_lat'                   => '',
      'gmap_lon'                   => '',
      'gmap_zoom'                  => '',
      'places_autocomplete'        => 0,
      'selected'									=> 1));
}

/**
 * Implements _webform_theme_component().
 */
function _webform_theme_gmap() {
  return array(
    'gmap_location' => array(
      'render element' => 'element',
    ),
  );
}

/**
 * Implements _webform_edit_component().
 */
function _webform_edit_gmap($component) {
  global $language;
  $path = drupal_get_path('module', 'webform_gmap_location');
  $g_link = 'http://maps.googleapis.com/maps/api/js?libraries=places&sensor=true&language=';
  $form = array();
  $form['#attached'] = array(
    'js' => array(
      $g_link . $language->language =>
      array(
        'type' => 'external',
        'weight' => 5,
      ),
      $path . '/js/gmap_admin.js' =>
      array(
        'type' => 'file',
        'weight' => 6,
        'scope' => 'footer',
      ),
      array(
        'type' => 'setting',
        'data' => array(
          'gmap' => array(
            'lat' => empty($component['extra']['gmap_lat']) ? GMAP_DEFAULT_LAT : $component['extra']['gmap_lat'],
            'lon' => empty($component['extra']['gmap_lon']) ? GMAP_DEFAULT_LON : $component['extra']['gmap_lon'],
            'path' => webform_gmap_location_get_marker_url('webform_gmap_location_marker_fid'),
            'zoom' => empty($component['extra']['gmap_zoom']) ? GMAP_DEFAULT_ZOOM : $component['extra']['gmap_zoom'])))));
  $form['extra']['places_autocomplete'] = array(
    '#type' => 'checkbox',
    '#default_value' => $component['extra']['places_autocomplete'],
    '#title' => t('Enable places autocomplete.'),
  );
  $form['extra']['selected'] = array(
    '#type' => 'select',
    '#title' => t('Number of values'),
    '#options' => webform_gmap_location_get_options_for_select(),
    '#default_value' => $component['extra']['selected'],
    '#description' => t('Maximum number of values users can enter for this field.'),
  );
  $form['extra']['width'] = array(
    '#type'              => 'textfield',
    '#title'             => t('Default width'),
    '#default_value'     => $component['extra']['width'],
    '#description'       => t('Enter the width map in px. If you need 100% width - set to 0.'),
    '#size'              => 10,
    '#field_suffix'      => 'px',
  );
  $form['extra']['height'] = array(
    '#type'              => 'textfield',
    '#title'             => t('Default height'),
    '#default_value'     => $component['extra']['height'],
    '#description'       => t('Enter the height map in px.'),
    '#size'              => 10,
    '#field_suffix'      => 'px',
  );
  $form['extra']['marker'] = array(
    '#title'             => t('Marker'),
    '#type'              => 'managed_file',
    '#description'       => t('Download the map marker.'),
    '#default_value'     => variable_get('webform_gmap_location_marker_fid', ''),
    '#upload_location'   => 'public://webform_gmap_location/',
    '#upload_validators' => array(
      'file_validate_extensions' => array('jpg png jpeg gif'),
    ),
  );
  $form['extra']['location'] = array(
    '#type'              => 'textfield',
    '#title'             => t('Default location'),
    '#default_value'     => $component['extra']['location'],
    '#description'       => t('Enter default location of the marker on the map.'),
    '#attributes' => array(
      'class' => array(
        'field-type-places-autocomplete',
      ),
      'id' => 'MapLocation',
    ),
  );
  $form['extra']['gmap'] = array(
    '#markup' => '<div id="gmap" style="width:100%;height:400px;"></div>',
  );
  $form['extra']['gmap_lat'] = array(
    '#type' => 'hidden',
    '#default_value' => empty($component['extra']['gmap_lat']) ? GMAP_DEFAULT_LAT : $component['extra']['gmap_lat'],
    '#attributes' => array('id' => 'gmap_lat'));
  $form['extra']['gmap_lon'] = array(
    '#type' => 'hidden',
    '#default_value' => empty($component['extra']['gmap_lon']) ? GMAP_DEFAULT_LON : $component['extra']['gmap_lon'],
    '#attributes' => array('id' => 'gmap_lon'));
  $form['extra']['gmap_zoom'] = array(
    '#type' => 'hidden',
    '#default_value' => empty($component['extra']['gmap_zoom']) ? GMAP_DEFAULT_ZOOM : $component['extra']['gmap_zoom'],
    '#attributes' => array('id' => 'gmap_zoom'));
  return $form;
}

/**
 * Implements _webform_render_component().
 */
function _webform_render_gmap($component, $value = NULL, $filter = TRUE) {
  global $language;
  $path = drupal_get_path('module', 'webform_gmap_location');
  $g_link = 'http://maps.googleapis.com/maps/api/js?libraries=places&sensor=true&language=';
  $form_item = array(
    '#type'             => 'markup',
    '#default_value'    => $filter ? _webform_filter_values($component['value']) : $component['value'],
    '#attributes'       => $component['extra']['attributes'],
    '#theme_wrappers'   => array('webform_element'),
    '#required'         => $component['required'] || $component['mandatory'],
    '#title'            => $filter ? _webform_filter_xss($component['name']) : $component['name'],
    '#title_display'    => $component['extra']['title_display'] ? $component['extra']['title_display'] : 'before',
    '#weight'           => $component['weight'],
    '#markup'           => webform_gmap_location_get_markup($component),
    '#translatable'     => array('title'),
    '#webform_component' => $component,
    '#theme' => 'gmap_location',
    '#process'          => array('webform_gmap_location_expand_hidden_field'),
    '#attached' => array(
      'js' => array(
        $g_link . $language->language =>
        array(
          'type' => 'external',
          'weight' => 5,
          'scope' => 'footer',
        ),
        $path . '/js/gmap_page.js' =>
        array(
          'type' => 'file',
          'weight' => 6,
          'scope' => 'footer',
        ),
        array(
          'type' => 'setting',
          'data' => array(
            'gmap' => array(
              'limit' => empty($component['extra']['selected']) ? GMAP_DEFAULT_LIMIT : $component['extra']['selected'],
              'lat' => empty($component['extra']['gmap_lat']) ? GMAP_DEFAULT_LAT : $component['extra']['gmap_lat'],
              'lon' => empty($component['extra']['gmap_lon']) ? GMAP_DEFAULT_LON : $component['extra']['gmap_lon'],
              'path' => webform_gmap_location_get_marker_url('webform_gmap_location_marker_fid'),
              'zoom' => empty($component['extra']['gmap_zoom']) ? GMAP_DEFAULT_ZOOM : $component['extra']['gmap_zoom']))))));
  if (isset($value)) {
    $form_item['#default_value'] = $value;
  }
  return $form_item;
}

/**
 * Add 3 hidden fields and loacation field.
 */
function webform_gmap_location_expand_hidden_field($element) {
  $component = $element["#webform_component"];
  if ($component["extra"]["places_autocomplete"] == 1) {
    $element['location'] = array(
      '#type'              => 'textfield',
      '#attributes' => array(
        'class' => array(
          'field-type-places-autocomplete',
        ),
        'id' => 'MapLocation-' . $component['cid'],
      ),
    );
  }
  $element['gmap_lat'] = array(
    '#type' => 'hidden',
    '#attributes' => array('id' => 'gmap-lat-' . $component['cid']),
  );
  $element['gmap_lon'] = array(
    '#type' => 'hidden',
    '#attributes' => array('id' => 'gmap-lon-' . $component['cid']),
  );
  $element['gmap_zoom'] = array(
    '#type' => 'hidden',
    '#attributes' => array('id' => 'gmap-zoom-' . $component['cid']),
  );
  return $element;
}

/**
 * Format the output of data for this component.
 */
function theme_gmap_location($variables) {
  $element = $variables['element'];
  return '<div class="webform-container-inline">' . $element["#markup"] . drupal_render_children($element) . '</div>';
}

/**
 * Implements _webform_analysis_component().
 */
function _webform_analysis_gmap($component, $sids = array(), $single = FALSE) {
  // Generate the list of options and questions.
  $query = db_select('webform_submitted_data', 'wsd', array('fetch' => PDO::FETCH_ASSOC))->fields('wsd', array('data'))->condition('nid', $component['nid'])->condition('cid', $component['cid']);
  if (count($sids)) {
    $query->condition('sid', $sids, 'IN');
  }
  $non_blanks = 0;
  $submissions = 0;
  $result = $query->execute();
  foreach ($result as $data) {
    if (drupal_strlen(trim($data['data'])) > 0) {
      $non_blanks++;
    }
    $submissions++;
  }
  $rows[0] = array(t('Left Blank'), ($submissions - $non_blanks));
  $rows[1] = array(t('User entered value'), $non_blanks);
  return $rows;
}

/**
 * Implements _webform_table_component().
 */
function _webform_table_gmap($component, $value) {
  return check_plain(empty($value[0]) ? '' : $value[0]);
}

/**
 * Implements _webform_csv_headers_component().
 */
function _webform_csv_headers_gmap($component, $export_options) {
  $header = array();
  $header[0] = '';
  $header[1] = '';
  $header[2] = $component['name'];
  return $header;
}

/**
 * Implements _webform_csv_data_component().
 */
function _webform_csv_data_gmap($component, $export_options, $value) {
  return !isset($value[0]) ? '' : $value[0];
}

/**
 * Return markup value.
 */
function webform_gmap_location_get_markup($component) {
  $width = (int) $component['extra']['width'] != 0 ? (int) $component['extra']['width'] : '100%';
  $width = $width ? $width . 'px' : '100%';
  $height = (int) $component['extra']['height'] ? (int) $component['extra']['height'] . 'px' : '300px';
  return '<div id="gmap-' . $component['cid'] . '" class="gmap-field" data-cid="' . $component['cid'] . '" style="display: block; width:' . $width . ';height:' . $height . ';"></div>';
}

/**
 * Return marker url.
 */
function webform_gmap_location_get_marker_url($name_field) {
  if (variable_get($name_field) != '') {
    $fid = variable_get('webform_gmap_location_marker_fid', '');
    $file = file_load($fid);
    return file_create_url($file->uri);
  }
  $path = drupal_get_path('module', 'webform_gmap_location');
  return file_create_url($path . '/img/marker.png');
}

/**
 * Return options.
 */
function webform_gmap_location_get_options_for_select() {
  $options = array();
  $options[0] = t('Unlimited');
  for ($i = 1; $i < 11; $i++) {
    $options[$i] = $i;
  }
  return $options;
}

/**
 * Implements _webform_display_component().
 */
function _webform_display_gmap($component, $value, $format = 'html') {
  $values = array();
  if (isset($value['gmap_lat']) and isset($value['gmap_lon'])) {
    $lats = explode(',', $value['gmap_lat']);
    $lons = explode(',', $value['gmap_lon']);
    if (count($lats) == count($lons)) {
      foreach ($lats as $index => $lat) {
        if (is_numeric($lats[$index]) and is_numeric($lons[$index])) {
          $values[$index] = $lats[$index] . ' ' . $lons[$index];
          $values[$index] = str_replace(',', '', $values[$index]);
          $values[$index] = trim($values[$index]);
        }
      }
    }
  }

  $values = implode(", ", $values);
  if (!empty($value['location'])) {
    $values .= ' (' . check_plain($value['location']) . ')';
  }

  return array(
    '#title' => $component['name'],
    '#weight' => $component['weight'],
    '#format' => $format,
    '#field_prefix' => '',
    '#field_suffix' => '',
    '#theme' => 'webform_display_textfield',
    '#theme_wrappers' => $format == 'html' ? array('webform_element') : array('webform_element_text'),
    '#value' => $values,
  );
}
