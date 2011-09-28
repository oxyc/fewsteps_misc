<?php

function site_settings_default_value($value, $default="") {
  return (!empty($value)) ? $value : $default;
}


function site_settings_settings($form, &$form_state) {
  $form['#tree'] = TRUE;


  /**
   * Site settings ************************************************************
   */

  $form['site_settings_site'] = array(
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#title' => t('General site information'),
  );

  $form['site_settings_site']['site_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Site name'),
    '#default_value' => variable_get('site_name', 'Drupal'),
    '#required' => TRUE,
  );

  $form['site_settings_site']['site_slogan'] = array(
    '#type' => 'textfield',
    '#title' => t('Slogan'),
    '#default_value' => variable_get('site_slogan', ''),
    '#description' => t("How this is used depends on your site's theme."),
  );
  $form['site_settings_site']['site_mail'] = array(
    '#type' => 'textfield',
    '#title' => t('E-mail address'),
    '#default_value' => variable_get('site_mail', ini_get('sendmail_from')),
    '#description' => t("The <em>From</em> address in automated e-mails sent during registration and new password requests, and other notifications. (Use an address ending in your site's domain to help prevent this e-mail being flagged as spam.)"),
    '#required' => TRUE,
  );

  /**
   * Contact information ******************************************************
   */

  $form['site_settings_contact'] = array(
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#title' => t('The sitewide contact information'),
  );

  $contact = site_settings_contact_get(); 

  /*
   * Contact - fn
   */
  $form['site_settings_contact']['fn'] = array(
    '#type' => 'fieldset',
    '#collapsible' => FALSE,
    '#title' => t('Name of the contact'),
  );

  $form['site_settings_contact']['fn']['fn'] = array(
    '#type' => 'textfield',
    '#title' => t('The full name of the contact'),
    '#default_value' => site_settings_default_value($contact['fn']['fn']),
  );

  $form['site_settings_contact']['fn']['org'] = array(
    '#type' => 'checkbox',
    '#title' => t('Is this an organization'),
    '#default_value' => site_settings_default_value($contact['fn']['org']),
  );

  /*
   * Address - adr
   */
  $form['site_settings_contact']['adr'] = array(
    '#type' => 'fieldset',
    '#collapsible' => FALSE,
    '#title' => t('Address information'),
  );

  $form['site_settings_contact']['adr']['street-address'] = array(
    '#type' => 'textfield',
    '#title' => t('The street address'),
    '#default_value' => site_settings_default_value($contact['adr']['street-address']),
  );

  $form['site_settings_contact']['adr']['locality'] = array(
    '#type' => 'textfield',
    '#title' => t('Locality'),
    '#default_value' => site_settings_default_value($contact['adr']['locality']),
  );

  $form['site_settings_contact']['adr']['postal-code'] = array(
    '#type' => 'textfield',
    '#title' => t('Postal code'),
    '#default_value' => site_settings_default_value($contact['adr']['postal-code']),
  );

  $form['site_settings_contact']['adr']['country-name'] = array(
    '#type' => 'textfield',
    '#title' => t('Country'),
    '#default_value' => site_settings_default_value($contact['adr']['country-name']),
  );

  /*
   * Telephone - tel
   */
  $form['site_settings_contact']['tel'] = array(
    '#type' => 'textfield',
    '#title' => t('Telephone number'),
    '#default_value' => site_settings_default_value($contact['tel']),
  );
  $form['#submit'][] = 'site_settings_settings_form_submit';

  return system_settings_form($form);
}

/**
 * system_settings_form_submit
 * 
 * Save site variables
 */
function site_settings_settings_form_submit($form, &$form_state) {

  // Exclude unnecessary elements.
  unset($form_state['values']['submit'], $form_state['values']['reset'], $form_state['values']['form_id'], $form_state['values']['op'], $form_state['values']['form_token'], $form_state['values']['form_build_id']);

  foreach ($form_state['values'] as $key => $value) {

    // Store site settings differently
    if ($key == 'site_settings_site') {
      foreach ($value as $site_settings_key => $site_settings_value) {
        variable_set($site_settings_key, $site_settings_value);
      }
      unset($form_state['values'][$key]);
    }
  }
}
