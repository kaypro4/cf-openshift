<?php

/**
 * @file
 * Sample hooks demonstrating usage in Saleforce Webforms.
 */

/**
 * @defgroup salesforce_webforms_hooks Salesforce Webform Module Hooks
 * @{
 * Salesforce Webforms' hooks enable other modules to intercept events within
 * the module.
 */

/**
 * Alter the list of Salesforce objects.
 *
 * @param array $objects
 *   An array of Salesforce object types.
 *   - key: object name.
 *   - value: object display name.
 */
function hook_salesforce_webforms_objects_alter(&$objects) {
  // Remove the Contact object.
  unset($objects['Contact']);
}

/**
 * Alter the available fields for an object.
 *
 * @param array $data
 *   Array of fields for an object.
 *   - key: Object name.
 *   - value: Array of fields.
 *     - key: field name.
 *     - value: field data structure as defined by Salesforce.
 */
function hook_salesforce_webforms_fields_alter(&$data) {
  // Discard the 'other' fields from the Contact object.
  if (isset($data['Contact'])) {
    foreach ($data['Contact'] as $field_name => $field_data) {
      if (substr($field_name, 0, 5) == 'Other') {
        unset($data['Contact'][$field_name]);
      }
    }
  }
}

/**
 * Modify a Saleforce mapping before it is saved.
 *
 * @param array $values
 *   The data to be saved to the database.
 *   - object: the name of the Salesforce object.
 *   - action: one of:
 *     - add - create a new record.
 *     - edit - update an existing record.
 *   - nid: Node ID.
 *   - map_id: the record to update when action == edit.
 *   - map_fields: Associative array of fields and values.
 */
function hook_salesforce_webforms_map_presave(&$values) {
  if ($values['object'] == 'Contact') {
    if (!isset($values['map_fields']['Account'])) {
      $values['map_fields']['Account'] = '01F000000scutO';
    }
  }
}

/**
 * Hook to allow extra processing after a mapping is saved.
 *
 * This hook isn't called until after the data is writtent to the database. If
 * the record needs to be updated, use hook_salesforce_webforms_map_presave
 * instead.
 *
 * @param array $values
 *   The data to be saved to the database.
 *   - object: the name of the Salesforce object.
 *   - action: one of:
 *     - add - create a new record.
 *     - edit - update an existing record.
 *   - nid: Node ID.
 *   - map_id: the record id.
 *   - map_fields: Associative array of fields and values.
 */
function hook_salesforce_webforms_map_save($values) {
  db_insert('my_table')
    ->fields(array(
      'action' => $values['action'],
      'mapid' => $values['map_id'],
    ))
    ->execute();
}

/**
 * Hook to allow extra processing after a submission is set to Salesforce.
 *
 * @param int $sid
 *   The webform submission ID.
 * @param array $ids
 *   An array of Salesforce ID records. Each record consists of:
 *   - mapname: The name of the map.
 *   - sfid: The Salesforce ID associated with this mapping.
 */
function hook_salesforce_webforms_save_submission($sid, $ids) {
  foreach ($ids as $id) {
    db_insert('my_table')
      ->fields(array(
        'sid' => $sid,
        'name' => $id['mapname'],
        'salesforce_id' => $id['sfid'],
      ))
      ->execute();
  }
}

/**
 * Hook to allow extra processing after a submission is deleted.
 *
 * @param int $sid
 *   The webform submission ID.
 */
function hook_salesforce_webforms_delete_submission($sid) {
  db_delete('my_table')
    ->condition('sid', $sid)
    ->execute();
}

/**
 * Alter hook to filter the list of objects of a given type.
 *
 * @param array $records
 *   Array of Saleforce objects.
 *   - key: Salesforce ID.
 *   - data: Label.
 */
function hook_salesforce_webforms_object_records_alter($records) {
  unset($records['01F000000scutO']);
}

/**
 * Alter hook to filter the list of picklists available.
 *
 * @param array $picklists
 *   Array of objects
 *   - key: Object name.
 *   - data: Array of picklists for that object.
 *     - key: object_name:picklist_name.
 *     - value: picklist label.
 */
function hook_salesforce_webforms_picklists_alter(&$picklists) {
  unset($picklists['Contact']);
}

/**
 * Alter hook to modify data before syncing to Salesforce.
 *
 * @param array $fields
 *   Associative array of key value pairs.
 * @param array $context
 *   Associative array of context data for this update.
 *   - mapping
 *     Salesforce mapping array.
 *   - node
 *     node object that the webform is attached to
 *   - submission
 *     webform submission array.
 *   - id
 *     Salesforce object ID to be updated.
 */
function hook_salesforce_webforms_push_params_alter(&$fields, $context) {
  switch ($context['map']['mapname']) {
    case 'my_map':
      unset($fields['my_field']);
      break;
  }
}

/**
 * @} salesforce_webforms_hooks
 */
