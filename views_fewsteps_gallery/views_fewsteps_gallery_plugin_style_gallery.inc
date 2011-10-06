<?php
/**
 * @file
 * Contains the list style plugin.
 */

/**
 * Style plugin to render each item of an ordered or unordered list.
 *
 * @ingroup views_style_plugins
 */
class views_fewsteps_gallery_plugin_style_gallery extends views_plugin_style {

  // Set default options
  function option_definition() {
    $options = parent::option_definition();
    $options['type'] = array('default' => 'Galleria');
    $options['skin'] = array('default' => 'Classic');

    return $options;
  }

  // Build the settings form for the view.
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['type'] = array(
      '#type' => 'select',
      '#title' => t('Select gallery type'),
      '#options' => array(
        'galleria' => 'Galleria',
      ),
      '#default_value' => $this->options['type'],
    );

    ctools_include('dependent');

    $form['skin'] = array(
      '#type' => 'select',
      '#title' => t('Select skin'),
      '#options' => array(
        'classic' => 'Classic',
      ),
      '#default_value' => $this->options['skin'],
      '#process' => array('ctools_dependent_process'),
      '#dependency' => array('#input[name="style_options[type]"]' => 'galleria'),
    );

    $form['thumbnail'] = array(
      '#type' => 'select',
      '#title' => t('Select thumbnail view mode'),
      '#options' => file_entity_view_mode_labels(),
      '#default_value' => $this->options['thumbnail'],
      '#process' => array('ctools_dependent_process'),
      '#dependency' => array('#input[name="style_options[type]"]' => 'galleria'),
    );

    $form['large'] = array(
      '#type' => 'select',
      '#title' => t('Select large view mode'),
      '#options' => file_entity_view_mode_labels(),
      '#default_value' => $this->options['large'],
      '#process' => array('ctools_dependent_process'),
      '#dependency' => array('#input[name="style_options[type]"]' => 'galleria'),
    );

    $form['fullscreen'] = array(
      '#type' => 'select',
      '#title' => t('Select fullscreen view mode'),
      '#options' => file_entity_view_mode_labels(),
      '#default_value' => $this->options['fullscreen'],
      '#process' => array('ctools_dependent_process'),
      '#dependency' => array('#input[name="style_options[type]"]' => 'galleria'),
    );
  }
}
