<?php
/**
 * @file
 * main_site_feature.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function main_site_feature_user_default_roles() {
  $roles = array();

  // Exported role: Blogger.
  $roles['Blogger'] = array(
    'name' => 'Blogger',
    'weight' => 4,
  );

  // Exported role: Editor.
  $roles['Editor'] = array(
    'name' => 'Editor',
    'weight' => 3,
  );

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 2,
  );

  return $roles;
}
