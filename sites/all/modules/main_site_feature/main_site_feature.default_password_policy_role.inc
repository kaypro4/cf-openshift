<?php
/**
 * @file
 * main_site_feature.default_password_policy_role.inc
 */

/**
 * Implements hook_default_password_policy_role().
 */
function main_site_feature_default_password_policy_role() {
  $export = array();

  $password_policy_role = new stdClass();
  $password_policy_role->disabled = FALSE; /* Edit this to true to make a default password_policy_role disabled initially */
  $password_policy_role->api_version = 1;
  $password_policy_role->rid = 2;
  $export['2'] = $password_policy_role;

  $password_policy_role = new stdClass();
  $password_policy_role->disabled = FALSE; /* Edit this to true to make a default password_policy_role disabled initially */
  $password_policy_role->api_version = 1;
  $password_policy_role->rid = 5;
  $export['5'] = $password_policy_role;

  return $export;
}
