<?php

/**
 * @file
 * Bartik's theme implementation to display a node.
 *
 * Available variables:
 * - $title: the (sanitized) title of the node.
 * - $content: An array of node items. Use render($content) to print them all,
 *   or print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $user_picture: The node author's picture from user-picture.tpl.php.
 * - $date: Formatted creation date. Preprocess functions can reformat it by
 *   calling format_date() with the desired parameters on the $created variable.
 * - $name: Themed username of node author output from theme_username().
 * - $node_url: Direct URL of the current node.
 * - $display_submitted: Whether submission information should be displayed.
 * - $submitted: Submission information created from $name and $date during
 *   template_preprocess_node().
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the
 *   following:
 *   - node: The current template type; for example, "theming hook".
 *   - node-[type]: The current node type. For example, if the node is a
 *     "Blog entry" it would result in "node-blog". Note that the machine
 *     name will often be in a short form of the human readable label.
 *   - node-teaser: Nodes in teaser form.
 *   - node-preview: Nodes in preview mode.
 *   The following are controlled through the node publishing options.
 *   - node-promoted: Nodes promoted to the front page.
 *   - node-sticky: Nodes ordered above other non-sticky nodes in teaser
 *     listings.
 *   - node-unpublished: Unpublished nodes visible only to administrators.
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 *
 * Other variables:
 * - $node: Full node object. Contains data that may not be safe.
 * - $type: Node type; for example, story, page, blog, etc.
 * - $comment_count: Number of comments attached to the node.
 * - $uid: User ID of the node author.
 * - $created: Time the node was published formatted in Unix timestamp.
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 * - $zebra: Outputs either "even" or "odd". Useful for zebra striping in
 *   teaser listings.
 * - $id: Position of the node. Increments each time it's output.
 *
 * Node status variables:
 * - $view_mode: View mode; for example, "full", "teaser".
 * - $teaser: Flag for the teaser state (shortcut for $view_mode == 'teaser').
 * - $page: Flag for the full page state.
 * - $promote: Flag for front page promotion state.
 * - $sticky: Flags for sticky post setting.
 * - $status: Flag for published status.
 * - $comment: State of comment settings for the node.
 * - $readmore: Flags true if the teaser content of the node cannot hold the
 *   main body content.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 * - $is_admin: Flags true when the current user is an administrator.
 *
 * Field variables: for each field instance attached to the node a corresponding
 * variable is defined; for example, $node->body becomes $body. When needing to
 * access a field's raw values, developers/themers are strongly encouraged to
 * use these variables. Otherwise they will have to explicitly specify the
 * desired field language; for example, $node->body['en'], thus overriding any
 * language negotiation rule that was previously applied.
 *
 * @see template_preprocess()
 * @see template_preprocess_node()
 * @see template_process()
 */
  $object = entity_metadata_wrapper('node', $node);
  $raw_title = $object->title->value();
  $raw_summary = $object->field_summary->value();
  $raw_event_address = $object->field_event_address->value();
  $encoded_event_address = urlencode($object->field_event_address->value());
?>

<script type="text/javascript">
addthisevent.settings({
  mouse   : false,
  css     : false,
  outlook   : {show:true, text:"Outlook Calendar"},
  google    : {show:true, text:"Google Calendar"},
  yahoo   : {show:true, text:"Yahoo Calendar"},
  ical    : {show:true, text:"iCal Calendar"},
  hotmail   : {show:true, text:"Hotmail Calendar"},
  facebook  : {show:true, text:"Facebook Calendar"}
});
</script>
<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <div class="content clearfix"<?php print $content_attributes; ?>>

  <h3 class="event-date"><?php print render($content['field_event_date']) ?></h3>

  <?php if (!empty($content['field_event_address'])) { ?>
    <p>

      <?php if ($content['field_link_to_google_maps_']['#items'][0]['value'] == 1) { ?>
        <strong>Location:</strong> <a href="https://maps.google.com?daddr=<?php print $encoded_event_address; ?>" target="_blank"><?php print $raw_event_address; ?></a>
      <?php }else{ ?>
        <?php print render($content['field_event_address']) ?>
      <?php } ?>
    </p>
  <?php } ?>

  <?php print render($content['field_banner_image']) ?>

  <p><?php print render($content['field_page_sections']) ?></p>

  <p><?php print render($content['field_event_cost']) ?></p>

  <p><h3><?php print render($content['field_event_registration_link']) ?></h3></p>

  <p><?php print render($content['field_event_files']) ?></p>

    <a href="#" title="Add to Calendar" class="addthisevent">
      Add to Your Calendar <i class="fa fa-chevron-down"></i>
      <span class="_start"><?php print render($content['field_event_date']['#items'][0]['value']) ?></span>
      <span class="_end"><?php print render($content['field_event_date']['#items'][0]['value2']) ?></span>
      <span class="_zonecode">6</span>
      <span class="_summary"><?php print $raw_title ?></span>
      <span class="_description"><?php print $raw_summary ?></span>
      <span class="_location"><?php print $raw_event_address ?></span>
      <span class="_organizer">City Fruit</span>
      <span class="_organizer_email">info@cityfruit.org</span>
      <span class="_all_day_event">false</span>
      <span class="_date_format">DD/MM/YYYY</span>
  </a>


  <p><?php print render($content['field_event_category']) ?></p>

  </div>

</div>
