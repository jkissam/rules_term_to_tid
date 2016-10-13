<?php

/**
 * implements hook_rules_action_info
 * creates custom action for rules
 */
function rules_term_to_tid_rules_action_info() {

	return array(
		'rules_term_to_tid_get_tid' => array(
			'label' => t('Convert term name to tid'),
			'group' => t('Entities'),
			'parameter' => array(
				'name' => array(
					'label' => t('Term name'),
					'type' => 'text',
				),
			),
			'provides' => array(
				'term_to_tid' => array(
					'type' => 'integer',
					'label' => t('Term TID'),
				),
			),
		),
		
	);

}

/**
 * callback function for getting term tid
 */
function rules_term_to_tid_get_tid($name) {

	$return = array(
		'term_to_tid' => null,
	);
	
	$terms = taxonomy_get_term_by_name($name);
	if (is_array($terms) && count($terms)) {
		$term = array_shift($terms);
		$return['term_to_tid'] = isset($term->tid) ? $term->tid : null;
	}

	return $return;

}
