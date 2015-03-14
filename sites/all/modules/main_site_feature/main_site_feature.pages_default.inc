<?php
/**
 * @file
 * main_site_feature.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function main_site_feature_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__basic_page_no_right_sidebar';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -24;
  $handler->conf = array(
    'title' => 'Basic Page - No Right Sidebar',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'basic_page_no_right_sidebar',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'entity_field_value:node:page:field_show_right_sidebar',
          'settings' => array(
            'field_show_right_sidebar' => array(
              'und' => array(
                0 => array(
                  'value' => 1,
                ),
              ),
            ),
            'field_show_right_sidebar_value' => array(
              0 => 1,
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => TRUE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'basic_no_right_col';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'title' => NULL,
      'nav' => NULL,
      'content' => NULL,
      'right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '340fda38-9e8e-41ef-af4a-be4a8d0539ea';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-80a5b0ac-8dd9-4918-8424-e3cbcbfbdbda';
    $pane->panel = 'content';
    $pane->type = 'node_title';
    $pane->subtype = 'node_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'link' => 0,
      'markup' => 'h1',
      'id' => '',
      'class' => '',
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '80a5b0ac-8dd9-4918-8424-e3cbcbfbdbda';
    $display->content['new-80a5b0ac-8dd9-4918-8424-e3cbcbfbdbda'] = $pane;
    $display->panels['content'][0] = 'new-80a5b0ac-8dd9-4918-8424-e3cbcbfbdbda';
    $pane = new stdClass();
    $pane->pid = 'new-038d4eec-194f-44f7-be58-5ec5b27b1880';
    $pane->panel = 'content';
    $pane->type = 'entity_view';
    $pane->subtype = 'node';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '038d4eec-194f-44f7-be58-5ec5b27b1880';
    $display->content['new-038d4eec-194f-44f7-be58-5ec5b27b1880'] = $pane;
    $display->panels['content'][1] = 'new-038d4eec-194f-44f7-be58-5ec5b27b1880';
    $pane = new stdClass();
    $pane->pid = 'new-76329eed-9a69-4c4c-905e-313f8876113c';
    $pane->panel = 'nav';
    $pane->type = 'block';
    $pane->subtype = 'menu_block-1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'auto-menu',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '76329eed-9a69-4c4c-905e-313f8876113c';
    $display->content['new-76329eed-9a69-4c4c-905e-313f8876113c'] = $pane;
    $display->panels['nav'][0] = 'new-76329eed-9a69-4c4c-905e-313f8876113c';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__basic_page_no_right_sidebar'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__basic_page_with_right_sidebar';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -25;
  $handler->conf = array(
    'title' => 'Basic Page - With Right Sidebar',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'basic_page_with_right_sidebar',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'entity_field_value:node:page:field_show_right_sidebar',
          'settings' => array(
            'field_show_right_sidebar' => array(
              'und' => array(
                0 => array(
                  'value' => 1,
                ),
              ),
            ),
            'field_show_right_sidebar_value' => array(
              0 => 1,
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'basic_right_col';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'left' => NULL,
      'middle' => NULL,
      'right' => NULL,
      'title' => NULL,
      'nav' => NULL,
      'content' => NULL,
    ),
    'left' => array(
      'style' => '-1',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'f0ddf8c3-67dd-4620-aa43-596d32944fbf';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-0cd7b032-f6db-4a0f-bce2-f8e1384c98d9';
    $pane->panel = 'content';
    $pane->type = 'entity_view';
    $pane->subtype = 'node';
    $pane->shown = TRUE;
    $pane->access = array(
      'logic' => 'and',
    );
    $pane->configuration = array(
      'view_mode' => 'full',
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '0cd7b032-f6db-4a0f-bce2-f8e1384c98d9';
    $display->content['new-0cd7b032-f6db-4a0f-bce2-f8e1384c98d9'] = $pane;
    $display->panels['content'][0] = 'new-0cd7b032-f6db-4a0f-bce2-f8e1384c98d9';
    $pane = new stdClass();
    $pane->pid = 'new-b0653d48-58ef-4a42-9aed-33bdebf65a04';
    $pane->panel = 'content';
    $pane->type = 'block';
    $pane->subtype = 'webform-client-block-111';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'about-us',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'b0653d48-58ef-4a42-9aed-33bdebf65a04';
    $display->content['new-b0653d48-58ef-4a42-9aed-33bdebf65a04'] = $pane;
    $display->panels['content'][1] = 'new-b0653d48-58ef-4a42-9aed-33bdebf65a04';
    $pane = new stdClass();
    $pane->pid = 'new-1965e5d1-50cb-4ccb-a9c8-bfb314346f28';
    $pane->panel = 'content';
    $pane->type = 'block';
    $pane->subtype = 'views-staff_listing-block';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'about-us/our-team',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Staff',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '1965e5d1-50cb-4ccb-a9c8-bfb314346f28';
    $display->content['new-1965e5d1-50cb-4ccb-a9c8-bfb314346f28'] = $pane;
    $display->panels['content'][2] = 'new-1965e5d1-50cb-4ccb-a9c8-bfb314346f28';
    $pane = new stdClass();
    $pane->pid = 'new-8400f80f-c296-4a11-97cd-7e17a68df13a';
    $pane->panel = 'nav';
    $pane->type = 'block';
    $pane->subtype = 'menu_block-1';
    $pane->shown = TRUE;
    $pane->access = array(
      'logic' => 'or',
    );
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'auto-menu',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '8400f80f-c296-4a11-97cd-7e17a68df13a';
    $display->content['new-8400f80f-c296-4a11-97cd-7e17a68df13a'] = $pane;
    $display->panels['nav'][0] = 'new-8400f80f-c296-4a11-97cd-7e17a68df13a';
    $pane = new stdClass();
    $pane->pid = 'new-f04453b0-de28-4c4e-9ce8-d65bfd1c102b';
    $pane->panel = 'right';
    $pane->type = 'block';
    $pane->subtype = 'block-6';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'span',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'f04453b0-de28-4c4e-9ce8-d65bfd1c102b';
    $display->content['new-f04453b0-de28-4c4e-9ce8-d65bfd1c102b'] = $pane;
    $display->panels['right'][0] = 'new-f04453b0-de28-4c4e-9ce8-d65bfd1c102b';
    $pane = new stdClass();
    $pane->pid = 'new-a4b80403-12fa-4288-8acb-9180ac3a236c';
    $pane->panel = 'right';
    $pane->type = 'block';
    $pane->subtype = 'views-blog_on_homepage-block';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'a4b80403-12fa-4288-8acb-9180ac3a236c';
    $display->content['new-a4b80403-12fa-4288-8acb-9180ac3a236c'] = $pane;
    $display->panels['right'][1] = 'new-a4b80403-12fa-4288-8acb-9180ac3a236c';
    $pane = new stdClass();
    $pane->pid = 'new-97d56a95-e1c5-4f76-8aa1-42f9ddce62ee';
    $pane->panel = 'right';
    $pane->type = 'block';
    $pane->subtype = 'views-upcoming_events-block';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '97d56a95-e1c5-4f76-8aa1-42f9ddce62ee';
    $display->content['new-97d56a95-e1c5-4f76-8aa1-42f9ddce62ee'] = $pane;
    $display->panels['right'][2] = 'new-97d56a95-e1c5-4f76-8aa1-42f9ddce62ee';
    $pane = new stdClass();
    $pane->pid = 'new-c6c7c984-3622-4883-bbfe-48246ac7a16a';
    $pane->panel = 'title';
    $pane->type = 'node_title';
    $pane->subtype = 'node_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'link' => 0,
      'markup' => 'h1',
      'id' => '',
      'class' => '',
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'c6c7c984-3622-4883-bbfe-48246ac7a16a';
    $display->content['new-c6c7c984-3622-4883-bbfe-48246ac7a16a'] = $pane;
    $display->panels['title'][0] = 'new-c6c7c984-3622-4883-bbfe-48246ac7a16a';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__basic_page_with_right_sidebar'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__blog_item';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -27;
  $handler->conf = array(
    'title' => 'Blog Item',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'blog_item',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'article' => 'article',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'basic_no_nav';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'title' => NULL,
      'content' => NULL,
      'right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '199515f7-3d9e-40ef-a924-7f4cdb8a235a';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-1f9fcf29-5364-493e-ae36-9ce5573afdd7';
    $pane->panel = 'content';
    $pane->type = 'node_created';
    $pane->subtype = 'node_created';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'format' => 'super_short',
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'posted-date',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '1f9fcf29-5364-493e-ae36-9ce5573afdd7';
    $display->content['new-1f9fcf29-5364-493e-ae36-9ce5573afdd7'] = $pane;
    $display->panels['content'][0] = 'new-1f9fcf29-5364-493e-ae36-9ce5573afdd7';
    $pane = new stdClass();
    $pane->pid = 'new-bc0b51c4-7cb7-408e-9fdf-58825c1b1300';
    $pane->panel = 'content';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'username',
      'title' => '',
      'body' => '<p>By&nbsp;<a href="/about-us/our-team#%node:author">%node:author</a></p>
',
      'format' => 'full_html',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'username',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'bc0b51c4-7cb7-408e-9fdf-58825c1b1300';
    $display->content['new-bc0b51c4-7cb7-408e-9fdf-58825c1b1300'] = $pane;
    $display->panels['content'][1] = 'new-bc0b51c4-7cb7-408e-9fdf-58825c1b1300';
    $pane = new stdClass();
    $pane->pid = 'new-401b1ff3-d25a-4d94-a6a8-ec83021156cc';
    $pane->panel = 'content';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_banner_image';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'image',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'image_style' => 'banner_image',
        'image_link' => '',
      ),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '401b1ff3-d25a-4d94-a6a8-ec83021156cc';
    $display->content['new-401b1ff3-d25a-4d94-a6a8-ec83021156cc'] = $pane;
    $display->panels['content'][2] = 'new-401b1ff3-d25a-4d94-a6a8-ec83021156cc';
    $pane = new stdClass();
    $pane->pid = 'new-e54d6980-3b24-42ad-b6e0-b383e30de995';
    $pane->panel = 'content';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_page_sections';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'paragraphs_view',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(
        'view_mode' => 'full',
      ),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'e54d6980-3b24-42ad-b6e0-b383e30de995';
    $display->content['new-e54d6980-3b24-42ad-b6e0-b383e30de995'] = $pane;
    $display->panels['content'][3] = 'new-e54d6980-3b24-42ad-b6e0-b383e30de995';
    $pane = new stdClass();
    $pane->pid = 'new-6eda123f-45f1-419a-9dcd-14a690292c15';
    $pane->panel = 'content';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_tags';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'inline',
      'formatter' => 'taxonomy_term_reference_link',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '6eda123f-45f1-419a-9dcd-14a690292c15';
    $display->content['new-6eda123f-45f1-419a-9dcd-14a690292c15'] = $pane;
    $display->panels['content'][4] = 'new-6eda123f-45f1-419a-9dcd-14a690292c15';
    $pane = new stdClass();
    $pane->pid = 'new-ed8c537c-d321-4d13-a397-70e58466cf59';
    $pane->panel = 'content';
    $pane->type = 'node_comments';
    $pane->subtype = 'node_comments';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'mode' => '1',
      'comments_per_page' => '10',
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = 'ed8c537c-d321-4d13-a397-70e58466cf59';
    $display->content['new-ed8c537c-d321-4d13-a397-70e58466cf59'] = $pane;
    $display->panels['content'][5] = 'new-ed8c537c-d321-4d13-a397-70e58466cf59';
    $pane = new stdClass();
    $pane->pid = 'new-2e160bda-50a8-4a0f-b150-6377e032feab';
    $pane->panel = 'content';
    $pane->type = 'node_comment_form';
    $pane->subtype = 'node_comment_form';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'anon_links' => 1,
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 6;
    $pane->locks = array();
    $pane->uuid = '2e160bda-50a8-4a0f-b150-6377e032feab';
    $display->content['new-2e160bda-50a8-4a0f-b150-6377e032feab'] = $pane;
    $display->panels['content'][6] = 'new-2e160bda-50a8-4a0f-b150-6377e032feab';
    $pane = new stdClass();
    $pane->pid = 'new-7c41c7ca-66f9-4e97-a9c7-c9122764f8c9';
    $pane->panel = 'right';
    $pane->type = 'block';
    $pane->subtype = 'block-6';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '7c41c7ca-66f9-4e97-a9c7-c9122764f8c9';
    $display->content['new-7c41c7ca-66f9-4e97-a9c7-c9122764f8c9'] = $pane;
    $display->panels['right'][0] = 'new-7c41c7ca-66f9-4e97-a9c7-c9122764f8c9';
    $pane = new stdClass();
    $pane->pid = 'new-4dac1d10-f38d-4f30-8caf-c4d335237b15';
    $pane->panel = 'right';
    $pane->type = 'block';
    $pane->subtype = 'views-related_blog_posts-block';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Related posts',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '4dac1d10-f38d-4f30-8caf-c4d335237b15';
    $display->content['new-4dac1d10-f38d-4f30-8caf-c4d335237b15'] = $pane;
    $display->panels['right'][1] = 'new-4dac1d10-f38d-4f30-8caf-c4d335237b15';
    $pane = new stdClass();
    $pane->pid = 'new-af6c2370-d15e-4333-8795-d226dbbdecc1';
    $pane->panel = 'title';
    $pane->type = 'node_title';
    $pane->subtype = 'node_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'link' => 0,
      'markup' => 'h1',
      'id' => '',
      'class' => '',
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'af6c2370-d15e-4333-8795-d226dbbdecc1';
    $display->content['new-af6c2370-d15e-4333-8795-d226dbbdecc1'] = $pane;
    $display->panels['title'][0] = 'new-af6c2370-d15e-4333-8795-d226dbbdecc1';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__blog_item'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__blog_landing';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -29;
  $handler->conf = array(
    'title' => 'Blog Landing',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'blog_landing',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'blog',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'basic_no_nav';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'title' => NULL,
      'content' => NULL,
      'right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '109e54f7-c0a1-4898-820d-a68f5eb7ea05';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-5bed6522-fa3d-4815-a593-51259620209c';
    $pane->panel = 'content';
    $pane->type = 'block';
    $pane->subtype = 'views-blog-blog_boxes';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '5bed6522-fa3d-4815-a593-51259620209c';
    $display->content['new-5bed6522-fa3d-4815-a593-51259620209c'] = $pane;
    $display->panels['content'][0] = 'new-5bed6522-fa3d-4815-a593-51259620209c';
    $pane = new stdClass();
    $pane->pid = 'new-08575915-5996-4235-a7ac-4ffc0cbdd2dc';
    $pane->panel = 'right';
    $pane->type = 'block';
    $pane->subtype = 'block-6';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '08575915-5996-4235-a7ac-4ffc0cbdd2dc';
    $display->content['new-08575915-5996-4235-a7ac-4ffc0cbdd2dc'] = $pane;
    $display->panels['right'][0] = 'new-08575915-5996-4235-a7ac-4ffc0cbdd2dc';
    $pane = new stdClass();
    $pane->pid = 'new-199e1cc3-427d-4e3c-b065-1a14a60df381';
    $pane->panel = 'right';
    $pane->type = 'block';
    $pane->subtype = 'views-latest_blog_comments-block';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Latest Comments',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '199e1cc3-427d-4e3c-b065-1a14a60df381';
    $display->content['new-199e1cc3-427d-4e3c-b065-1a14a60df381'] = $pane;
    $display->panels['right'][1] = 'new-199e1cc3-427d-4e3c-b065-1a14a60df381';
    $pane = new stdClass();
    $pane->pid = 'new-dc6cb9f3-ac0a-4362-9842-a0116a6b365c';
    $pane->panel = 'right';
    $pane->type = 'block';
    $pane->subtype = 'views-upcoming_events-block';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'dc6cb9f3-ac0a-4362-9842-a0116a6b365c';
    $display->content['new-dc6cb9f3-ac0a-4362-9842-a0116a6b365c'] = $pane;
    $display->panels['right'][2] = 'new-dc6cb9f3-ac0a-4362-9842-a0116a6b365c';
    $pane = new stdClass();
    $pane->pid = 'new-53d6c890-aa6c-4fdb-a92b-76017953a69c';
    $pane->panel = 'title';
    $pane->type = 'page_title';
    $pane->subtype = 'page_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'markup' => 'h1',
      'class' => '',
      'id' => '',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '53d6c890-aa6c-4fdb-a92b-76017953a69c';
    $display->content['new-53d6c890-aa6c-4fdb-a92b-76017953a69c'] = $pane;
    $display->panels['title'][0] = 'new-53d6c890-aa6c-4fdb-a92b-76017953a69c';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__blog_landing'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__calendar_item';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -26;
  $handler->conf = array(
    'title' => 'Calendar Item',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'calendar_item',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'event' => 'event',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'basic_no_nav';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'title' => NULL,
      'content' => NULL,
      'right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '881f11b9-fd18-46ba-be29-e927c2dd7018';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-ffa2286e-b553-43d2-bd9b-7e6409ad25cf';
    $pane->panel = 'content';
    $pane->type = 'entity_view';
    $pane->subtype = 'node';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'ffa2286e-b553-43d2-bd9b-7e6409ad25cf';
    $display->content['new-ffa2286e-b553-43d2-bd9b-7e6409ad25cf'] = $pane;
    $display->panels['content'][0] = 'new-ffa2286e-b553-43d2-bd9b-7e6409ad25cf';
    $pane = new stdClass();
    $pane->pid = 'new-0edb27c3-760b-4905-b290-f32ed39ec8b3';
    $pane->panel = 'right';
    $pane->type = 'block';
    $pane->subtype = 'block-6';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '0edb27c3-760b-4905-b290-f32ed39ec8b3';
    $display->content['new-0edb27c3-760b-4905-b290-f32ed39ec8b3'] = $pane;
    $display->panels['right'][0] = 'new-0edb27c3-760b-4905-b290-f32ed39ec8b3';
    $pane = new stdClass();
    $pane->pid = 'new-bff5ac77-34a5-472b-80c0-90550b6da9e1';
    $pane->panel = 'right';
    $pane->type = 'block';
    $pane->subtype = 'views-upcoming_events-block';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'bff5ac77-34a5-472b-80c0-90550b6da9e1';
    $display->content['new-bff5ac77-34a5-472b-80c0-90550b6da9e1'] = $pane;
    $display->panels['right'][1] = 'new-bff5ac77-34a5-472b-80c0-90550b6da9e1';
    $pane = new stdClass();
    $pane->pid = 'new-a81de219-75fd-4686-ae80-fa0099388f4f';
    $pane->panel = 'title';
    $pane->type = 'node_title';
    $pane->subtype = 'node_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'link' => 0,
      'markup' => 'h1',
      'id' => '',
      'class' => '',
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'a81de219-75fd-4686-ae80-fa0099388f4f';
    $display->content['new-a81de219-75fd-4686-ae80-fa0099388f4f'] = $pane;
    $display->panels['title'][0] = 'new-a81de219-75fd-4686-ae80-fa0099388f4f';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-a81de219-75fd-4686-ae80-fa0099388f4f';
  $handler->conf['display'] = $display;
  $export['node_view__calendar_item'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__calendar_landing';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -28;
  $handler->conf = array(
    'title' => 'Calendar Landing',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'calendar_landing',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'calendar',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'basic_no_nav';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'title' => NULL,
      'content' => NULL,
      'right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '625c64ec-acbf-4682-a289-9fae04c7290b';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-4fe8dc0d-9bd8-4612-9552-23616a4d6b11';
    $pane->panel = 'content';
    $pane->type = 'block';
    $pane->subtype = 'views-calendar-calendar_boxes';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '4fe8dc0d-9bd8-4612-9552-23616a4d6b11';
    $display->content['new-4fe8dc0d-9bd8-4612-9552-23616a4d6b11'] = $pane;
    $display->panels['content'][0] = 'new-4fe8dc0d-9bd8-4612-9552-23616a4d6b11';
    $pane = new stdClass();
    $pane->pid = 'new-400624c1-cd00-4f03-ae3f-0159da4a6e6d';
    $pane->panel = 'right';
    $pane->type = 'block';
    $pane->subtype = 'block-6';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '400624c1-cd00-4f03-ae3f-0159da4a6e6d';
    $display->content['new-400624c1-cd00-4f03-ae3f-0159da4a6e6d'] = $pane;
    $display->panels['right'][0] = 'new-400624c1-cd00-4f03-ae3f-0159da4a6e6d';
    $pane = new stdClass();
    $pane->pid = 'new-cc5ee74c-c5ed-4048-ac60-c1c824a203ab';
    $pane->panel = 'right';
    $pane->type = 'block';
    $pane->subtype = 'views-upcoming_events-block';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'cc5ee74c-c5ed-4048-ac60-c1c824a203ab';
    $display->content['new-cc5ee74c-c5ed-4048-ac60-c1c824a203ab'] = $pane;
    $display->panels['right'][1] = 'new-cc5ee74c-c5ed-4048-ac60-c1c824a203ab';
    $pane = new stdClass();
    $pane->pid = 'new-4d3124d9-92d4-47b5-bdb4-c8a8fc771fa8';
    $pane->panel = 'title';
    $pane->type = 'page_title';
    $pane->subtype = 'page_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'markup' => 'h1',
      'class' => '',
      'id' => '',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '4d3124d9-92d4-47b5-bdb4-c8a8fc771fa8';
    $display->content['new-4d3124d9-92d4-47b5-bdb4-c8a8fc771fa8'] = $pane;
    $display->panels['title'][0] = 'new-4d3124d9-92d4-47b5-bdb4-c8a8fc771fa8';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__calendar_landing'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__default';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -23;
  $handler->conf = array(
    'title' => 'Default',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'default',
  );
  $display = new panels_display();
  $display->layout = 'basic_right_col';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'title' => NULL,
      'nav' => NULL,
      'content' => NULL,
      'right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '3b088851-b991-4594-9d64-3d98d948840d';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-a8e8b532-2296-4e16-965a-90704d616bd2';
    $pane->panel = 'content';
    $pane->type = 'entity_view';
    $pane->subtype = 'node';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'col-md-12',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'a8e8b532-2296-4e16-965a-90704d616bd2';
    $display->content['new-a8e8b532-2296-4e16-965a-90704d616bd2'] = $pane;
    $display->panels['content'][0] = 'new-a8e8b532-2296-4e16-965a-90704d616bd2';
    $pane = new stdClass();
    $pane->pid = 'new-1df0a6e1-7969-49fc-8c9c-bbfa7b8c55d9';
    $pane->panel = 'title';
    $pane->type = 'node_title';
    $pane->subtype = 'node_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'link' => 0,
      'markup' => 'none',
      'id' => '',
      'class' => '',
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '1df0a6e1-7969-49fc-8c9c-bbfa7b8c55d9';
    $display->content['new-1df0a6e1-7969-49fc-8c9c-bbfa7b8c55d9'] = $pane;
    $display->panels['title'][0] = 'new-1df0a6e1-7969-49fc-8c9c-bbfa7b8c55d9';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-1df0a6e1-7969-49fc-8c9c-bbfa7b8c55d9';
  $handler->conf['display'] = $display;
  $export['node_view__default'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__home_page';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -30;
  $handler->conf = array(
    'title' => 'Home Page',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'home_page',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'home
<front>',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'home';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'header' => NULL,
      'blocks' => NULL,
      'content' => NULL,
      'first' => NULL,
      'second' => NULL,
      'third' => NULL,
      'fourth' => NULL,
    ),
    'second' => array(
      'style' => 'naked',
    ),
    'third' => array(
      'style' => '-1',
    ),
    'fourth' => array(
      'style' => 'naked',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '9688695a-1760-49aa-9e63-e1cee2dbaa9a';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-1394f917-d6e2-4531-ba21-3d5b947e3638';
    $pane->panel = 'first';
    $pane->type = 'block';
    $pane->subtype = 'block-7';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '1394f917-d6e2-4531-ba21-3d5b947e3638';
    $display->content['new-1394f917-d6e2-4531-ba21-3d5b947e3638'] = $pane;
    $display->panels['first'][0] = 'new-1394f917-d6e2-4531-ba21-3d5b947e3638';
    $pane = new stdClass();
    $pane->pid = 'new-590fe94b-9f88-4276-bec6-159ef8e9e1c5';
    $pane->panel = 'first';
    $pane->type = 'block';
    $pane->subtype = 'block-10';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '590fe94b-9f88-4276-bec6-159ef8e9e1c5';
    $display->content['new-590fe94b-9f88-4276-bec6-159ef8e9e1c5'] = $pane;
    $display->panels['first'][1] = 'new-590fe94b-9f88-4276-bec6-159ef8e9e1c5';
    $pane = new stdClass();
    $pane->pid = 'new-c15d0c08-e6f6-499d-9a27-d998c34b38cb';
    $pane->panel = 'fourth';
    $pane->type = 'block';
    $pane->subtype = 'block-5';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Photos from the orchard',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'col-xs-12 col-sm-8 col-md-8 col-lg-8',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'c15d0c08-e6f6-499d-9a27-d998c34b38cb';
    $display->content['new-c15d0c08-e6f6-499d-9a27-d998c34b38cb'] = $pane;
    $display->panels['fourth'][0] = 'new-c15d0c08-e6f6-499d-9a27-d998c34b38cb';
    $pane = new stdClass();
    $pane->pid = 'new-2aa95172-cc6a-4b61-923a-4d964e10f3ce';
    $pane->panel = 'fourth';
    $pane->type = 'block';
    $pane->subtype = 'block-4';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Twitter',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'col-xs-12 col-sm-4 col-md-4 col-lg-4',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '2aa95172-cc6a-4b61-923a-4d964e10f3ce';
    $display->content['new-2aa95172-cc6a-4b61-923a-4d964e10f3ce'] = $pane;
    $display->panels['fourth'][1] = 'new-2aa95172-cc6a-4b61-923a-4d964e10f3ce';
    $pane = new stdClass();
    $pane->pid = 'new-3a832062-7051-42af-b26f-9091124aa165';
    $pane->panel = 'second';
    $pane->type = 'block';
    $pane->subtype = 'views-features-block';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'row',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '3a832062-7051-42af-b26f-9091124aa165';
    $display->content['new-3a832062-7051-42af-b26f-9091124aa165'] = $pane;
    $display->panels['second'][0] = 'new-3a832062-7051-42af-b26f-9091124aa165';
    $pane = new stdClass();
    $pane->pid = 'new-a1202229-d4ab-471e-8d99-9b6807730ae0';
    $pane->panel = 'second';
    $pane->type = 'block';
    $pane->subtype = 'block-3';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'col-md-3 by-the-numbers',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'a1202229-d4ab-471e-8d99-9b6807730ae0';
    $display->content['new-a1202229-d4ab-471e-8d99-9b6807730ae0'] = $pane;
    $display->panels['second'][1] = 'new-a1202229-d4ab-471e-8d99-9b6807730ae0';
    $pane = new stdClass();
    $pane->pid = 'new-84c7b086-0d94-48fc-a8c2-3c65aad46b69';
    $pane->panel = 'third';
    $pane->type = 'block';
    $pane->subtype = 'block-9';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '84c7b086-0d94-48fc-a8c2-3c65aad46b69';
    $display->content['new-84c7b086-0d94-48fc-a8c2-3c65aad46b69'] = $pane;
    $display->panels['third'][0] = 'new-84c7b086-0d94-48fc-a8c2-3c65aad46b69';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__home_page'] = $handler;

  return $export;
}
