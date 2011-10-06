<?php

function theme_views_fewsteps_gallery_main_section($variables) {
  $attributes['id'] = "{$variables['plugin']}_main_{$variables['id']}";
  $attributes['class'] = array("{$variables['plugin']}_main views", "gallery_main");
  $attributes = drupal_attributes($attributes);

  return "<div$attributes>{$variables['hidden_elements']}</div>";
}

