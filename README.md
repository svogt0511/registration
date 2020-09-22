# Drupal 7 Custom Module: registration
Drupal 7 custom 'registration' module for the dgi coding test.

This is my implementation of the coding test as described in the [dgi Coding Test](https://gist.github.com/jordandukart/b602fa64f50bb14ba579d2a51f0fdee5),
which involves creating a custom Drupal 7 module that allows students to 
register in a course.  It includes:

- A database with a 'registration' table managed by the Drupal back end. 

- A page with a form for adding student registrations which stores
them in the 'registration' table on submission.  The form is implemented using the 
Drupal Forms API.

- Limited access to the registration form page to authenticated users.  

- A block that calculates the number of students signed up and displays it in the
content region of the <front> page only.

- A drush command to list the students signed up for the course. 

## Installation

This is a Drupal 7 module is called 'registration'.  It can be installed 
like any other Drupal 7 module.  Move the code to the 
{site_root}/sites/all/modules directory.  Go to the modules page and 
enable the 'registration' module in the 'custom-modules' package. 
This creates the 'registration' table in the site's database. 

## Registration Form

The page can be reached by either using the 'Course Registration' 
link in the 'Navigation' menu, or by going to /registration.
Simply fill out the form and press the 'Register' button to register. 
It should report a successful registration which can be seen as 
an entry in the database table.

The link in the 'Navigation' menu can be disabled or moved to another menu using the Drupal 7 Menu UI (at admin/structure/menu).

## Registration Access

Access to the registration form is set to 'Authenticated User' by default.  It can be managed in the Drupal 7 Permissions UI (at /admin/people/permissions).

## Registration Block

A block appears in the content region of the <front-page> only.
However, this may be managed by configuring the block in the Drupal Blocks UI (admin/stuctur/blocks).

## Drupal command

The Drush command that will print a list of registered students is:  

```
drush reg-student-list
```

abbreviated as:

```
drush rsl
```
