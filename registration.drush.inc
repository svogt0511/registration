<?php

/**
 * @file
 * Install, update and uninstall functions for the registration module.
 */

/**
 * Implements hook_drush_command().
 */
function registration_drush_command() {

  $commands['my-example-command'] = array(
    'callback' => 'registration_my_example_command',
    'description' => 'This is my example command.',
    'aliases' => array('mec'),
    'arguments' => array(
      'arg1' => 'My custom argument 1.',
      'arg2' => 'My custom argument 2.',
    ),
    'options' => array(
      'opt1' => 'My custom option.',
    ),
    'examples' => array(
      'drush mec' => 'Print my example command.',
      'drush mec myargument' => 'Print my example command with an argument "myargument".',
      'drush mec myargument --opt1=myoption' => 'Print my example command with an argument "myargument" and an option "myoption".',
    ),
  );

  return $commands;
}

/**
 * Drush command logic.
 */
function registration_my_example_command($arg1 = 'N/A', $arg2 = 'N/A') {
  $opt1 = drush_get_option('opt1', 'N/A');
  $tokens = array('@arg1' => $arg1, '@opt1' => $opt1);

  $header = array(dt('ID'), dt('UID'), dt('NAME'), dt('SURNAME'), dt('AGE'));
  $widths = array('pid' => 5, 'uid' => 20, 'name' => 30, 'surname' => 25);

  $reg_list = registration_drush_registration_list();

  if (!empty($reg_list)) {
    array_unshift($reg_list, $header);
    $output = drush_format_table($reg_list, TRUE, $widths);
    drush_print(dt(''));
    drush_print(dt('STUDENTS REGISTERED'));
    drush_print($output);
    drush_print(dt(''));
  }
  else {
    drush_print(dt('No students have registered yet.'));
  }
}

/**
 * Gets list from db 'registration' table for output by drush command.
 */
function registration_drush_registration_list() {
  $rows = array();

  // Get all entries in the registration table.
  if ($entries = registration_entry_load()) {
    $rows = array();
    foreach ($entries as $entry) {
      // Sanitize the data before handing it off to the theme layer.
      $rows[] = array_map('check_plain', (array) $entry);
    }
  }

  return $rows;
}
