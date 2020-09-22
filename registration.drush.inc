<?php

/**
 * @file
 * Install, update and uninstall functions for the registration module.
 */

/**
 * Implements hook_drush_command().
 */
function registration_drush_command() {
  $commands['reg-student-list'] = array(
    'callback' => 'drush_registration_reg_student_list',
    'description' => 'Get a list of students signed up for this course.',
    'aliases' => array('rsl'),
    'arguments' => array(),
    'options' => array(),
    'examples' => array(
      'drush rsl' => 'Print a list of students registered for a given class.',
    ),
  );

  return $commands;
}

/**
 * Drush command logic.
 *
 * Drush_[MODULE_NAME]_[COMMAND_NAME]().
 */
function drush_registration_reg_student_list() {
  $reg_list = drush_registration_get_list();

  if (!empty($reg_list)) {
    drush_print(dt(''));
    drush_print(dt('STUDENTS REGISTERED - ' . REGISTRATION_COURSE_TITLE));
    drush_print(dt(''));

    foreach ($reg_list as $reg) {
      drush_print(dt('@last, @first',
        ['@last' => $reg['surname'], '@first' => $reg['name']])
      );
    }
    drush_print(dt(''));
  }
  else {
    drush_print(dt('No students have registered yet.'));
  }
}

/**
 * Gets list from db 'registration' table for output by drush command.
 */
function drush_registration_get_list() {
  $rows = array();

  // Get all entries in the registration table.
  if ($entries = registration_selective_list(array('surname', 'name'))) {
    $rows = array();
    foreach ($entries as $entry) {
      // Sanitize the data before handing it off to the theme layer.
      $rows[] = array_map('check_plain', (array) $entry);
    }
  }

  return $rows;
}
