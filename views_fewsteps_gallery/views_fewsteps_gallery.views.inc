<?php

/**
 * Implements hook_views_plugins().
 */
function views_fewsteps_gallery_views_plugins() {
  $path = drupal_get_path('module', 'views_fewsteps_gallery');
  return array(
    'style' => array(
      'fewsteps_gallery' => array(
        'title' => t('Fewsteps Gallery'),
        'help' => t('Applies jQuery effects to views output.'),
        'handler' => 'views_fewsteps_gallery_plugin_style_gallery',
        'uses row plugin' => TRUE,
        'uses fields' => TRUE,
        'uses options' => TRUE,
        'uses_grouping' => FALSE,
        'type' => 'normal',
        'parent' => 'default',
        'path' => $path,
        'theme' => 'views_fewsteps_gallery',
        'theme path' => $path,
        'theme file' => 'views_fewsteps_gallery.theme.inc',
      ),
    ),
  );
}
