<?php
/**
 * @file
 * main_site_feature.default_password_policy.inc
 */

/**
 * Implements hook_default_password_policy().
 */
function main_site_feature_default_password_policy() {
  $export = array();

  $password_policy = new stdClass();
  $password_policy->disabled = FALSE; /* Edit this to true to make a default password_policy disabled initially */
  $password_policy->api_version = 1;
  $password_policy->name = 'Password complexity';
  $password_policy->description = '';
  $password_policy->enabled = TRUE;
  $password_policy->policy = array(
    'complexity' => '3',
    'length' => '8',
    'username' => '1',
    'uppercase' => '1',
    'lowercase' => '1',
    'history' => '4',
    'punctuation' => '1',
  );
  $password_policy->created = 1426001974;
  $password_policy->expiration = 180;
  $password_policy->warning = '';
  $password_policy->weight = FALSE;
  $export['Password complexity'] = $password_policy;

  return $export;
}
