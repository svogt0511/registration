# Drupal 7 Custom Module: registration
Drupal 7 custom 'registration' module for the dgi coding test.  

Coding test as described in the [dgi Coding Test](https://gist.github.com/jordandukart/b602fa64f50bb14ba579d2a51f0fdee5).  

Copy of description included below.

# dgi Coding Test

## Story

The University of Prince Edward Island is gauging interest for a new summer course, "Theory of Computing 2: Electric Boogaloo". To determine whether or not they have enough students willing to sign up they require the following in a new Drupal 7 module:

* A page that allows a student to sign up for the course and stores the information.
 
* A block that calculates the amount of students currently signed up and displays it on the main page.

* Ability on the command line to generate a list of all signed up students.

## Technical Requirements

* Uses a database table managed within Drupal as the backend for storing and retrieval of the students' information (this table gets created when the module is enabled).

* Form is created with the [Drupal Form API](https://api.drupal.org/api/drupal/includes%21form.inc/group/form_api/7.x) and is only accessible to logged in users.

* [Block](https://www.drupal.org/docs/7/core/modules/block/overview) that is created placed in the "content" region of the page on the frontpage (`<front>`) only. If the user is not signed up, and not anonymous, a link to the sign up page should also be present underneath.

* Uses a [Drush](https://www.drush.org/) command implementation in the module to generate the list of students.

## Implementation & Notes

* To install Drupal feel free to setup a LAMP/WAMP stack or use something like [Acquia's Dev Desktop](https://dev.acquia.com/downloads) or [drupal-vm](https://github.com/geerlingguy/drupal-vm) that'll provide a quick and easy setup. NOTE: This should be done in Drupal 7 for the purpose of this coding test.

* Complying to Drupal [coding standards](https://www.drupal.org/docs/develop/standards/coding-standards) and naming conventions using [PHPCS and Drupal's sniffs](https://www.drupal.org/node/1419988) would be preferred.

* Submission of the module only via a Git repository or in an archive would be preferred.

* A good resource would be the Drupal [Examples](https://www.drupal.org/project/examples) module.
