/**!
 * project-site: tim-carter.com
 * @author Tim Carter
 * @version 1.10
 * Copyright 2012, Tim Carter
 * Dual licensed under the MIT or GPL Version 2 licenses.
 */

jQuery.fn.dialogX = function (options) {
    options = jQuery.extend({
        hideElementsThatCanTakePriority:true,
        backgroundOpacity:"5",
        loaderIcon:"/images/ajax-loader.gif",
        type:"image", //image or dialog,
        
        
        openMode:'click', //click,mouseFollow (use mouseFollow for when hovering images then src image will follow mouse cursor)
        mouseFollowAlign:'right', //Align image left or right of cursor
        preloadAllImagesBeforeLoading:false, //WILL SLOW DOWN THE INITIAL LOADING OF YOUR PAGE IF TRUE
        
        imageBorderSize:"1",
        imageBorderColor:"black",
        
        initialDialogHeight:"200",
        initialDialogWidth:"200",
        initialDialogMessage:"Loading please wait",
        
        dialogContainerBorderSize:1,
        dialogContainerBgColor:"white",
        dialogContainerBorderColor:"#75a7b8",
        dialogContainerPadding:"20",
        
        dialogContentBorderSize:"0",
        dialogContentBorderColor:"white",
        dialogContentBgColor:"white",

        restrictImageSize:true,
        imageMaxWidth:800,
        imageMaxHeight:600,
        content : "",
        ajaxUrl:"",
        ajaxType:"POST",
        ajaxCache:false,
        ajaxSync:false,
        ajaxData:"",
        ajaxDataType:"html"
        
        
        ,debug:false
        
        
    }, options);
    
    if(options.debug){
        $("<div id='debug' style='width:100%;height:50px;z-index:11100;position:fixed;bottom:0px;left:0px;background-color:black;color:red;'></div>").appendTo("body");
    }
    
    var object = this;
    
    var mouseX = 0;
    var mouseY = 0;
    
    function getScreen() {
        var d = []; d['height'] = $(window).height(),d['width'] = document.documentElement.clientWidth;
        return d;
    };
    function dialogRemove(){
        //return false;
        $dialog.remove();
        if(options.openMode!='mouseFollow'){
            $bg.remove();
        }
        if(options.hideElementsThatCanTakePriority){
            $('embed, object, select').css({ 'visibility' : 'visible' });
        }
        $(window).scroll().unbind();
        $(window).resize().unbind();
        $(document).mousemove().unbind();
    };
    function dialog(o){
        if(options.openMode!='mouseFollow'){
            $bg = $("<div class='tc_dialog_bg' style='z-index:10000;position:fixed;top:0px;left:0px;width:"+(document.documentElement.scrollWidth)+"px;height:"+(document.documentElement.scrollHeight)+"px;background-color:black;filter:alpha(opacity="+(options.backgroundOpacity + "0")+");-moz-opacity:"+(options.backgroundOpacity/10)+";-khtml-opacity: "+(options.backgroundOpacity/10)+";opacity: "+(options.backgroundOpacity/10)+";'></div>").appendTo("body").fadeIn();
            $bg.click(function(){
                dialogRemove();
            });
            var position = "fixed";
            var top = Math.round((getScreen().height / 2) - (options.initialDialogHeight / 2));
            var left = Math.round((getScreen().width / 2) - (options.initialDialogWidth / 2));
        }else{
            var position = "absolute";
            var top = "0";
            var left = "0";
        }
        $dialog = $("<div class='tc_dialog_container' style='position:"+position+";top:"+top+"px;left:"+left+"px;width:"+options.initialDialogWidth+"px;height:"+options.initialDialogHeight+"px;background-color:"+options.dialogContainerBgColor+";z-index:10001;border:"+options.dialogContainerBorderSize+"px solid "+options.dialogContainerBorderColor+";padding:"+options.dialogContainerPadding+"px;'><div style='width:100%;height:100%;text-align:center;background-color:"+options.dialogContentBgColor+";border:"+options.dialogContentBorderSize+"px solid "+options.dialogContentBorderColor+";' class='tc_dialog_content'>"+(options.type=='image' || options.src!="" ? "<img src='"+options.loaderIcon+"'><br>"+options.initialDialogMessage+"" : "")+"</div></div>").appendTo("body").fadeIn();
        if(options.type=="image"){
            getImage(o);
        }
        if(options.type=="dialog"){
            if(options.ajaxUrl!=""){
                $.ajax({
                    async:options.ajaxSync,
                    type:options.ajaxType,
                    url:options.ajaxUrl,
                    cache:options.ajaxCache,
                    data:options.ajaxData,
                    dataType:options.ajaxDataType,
                    success:function(html){
                        options.content = html;
                    }
                });
            }
            var width = $(options.content).width();
            var height = $(options.content).height();
            //alert(width + " " + options.openMode);
            $dialog.each(function(){
                var left = Math.round((getScreen().width / 2) - (width / 2));
                var top = Math.round((getScreen().height / 2) - (height / 2));
                if(options.openMode!='mouseFollow'){
                    $(this).animate({
                        width:width,
                        height:height,
                        left:left,
                        top:top
                    },500,function(){
                        $(this).find(".tc_dialog_content").html(options.content);
                    });
                }else{
                    $(this).css({
                        width:width,
                        height:height,
                        left:left,
                        top:top
                    });
                    $(this).find(".tc_dialog_content").html(options.content);
                }
            });
        }
        $(window).scroll(function(){repos();}).resize(function(){repos();});
    };
    function getImage(o){
        var src = (o.src!=undefined ? o.src : "");
        img = new Image();
        img.src = src;
        img.onload = function(){
            var width = img.width;
            var height = img.height;
            if(options.restrictImageSize){
                var x_ratio = options.imageMaxWidth / width; 
                var y_ratio = options.imageMaxHeight / height; 
                if((width <= options.imageMaxWidth) && (height <= options.imageMaxHeight)){ 
                    width = width; 
                    height = height; 
                }else if((x_ratio * height) < options.imageMaxHeight){ 
                    height = Math.ceil(x_ratio * height); 
                    width = options.imageMaxWidth; 
                }else{ 
                    width = Math.ceil(y_ratio * width); 
                    height = options.imageMaxHeight; 
                } 
            }
            $dialog.each(function(){
                //alert($(this).attr("id"));
                
                if(options.openMode!='mouseFollow'){
                    var left = Math.round((getScreen().width / 2) - (width / 2));
                    var top = Math.round((getScreen().height / 2) - (height / 2));
                    $(this).animate({
                        width:(width),
                        height:(height),
                        left:left,
                        top:top
                    },500,function(){
                        $(this).find(".tc_dialog_content").html("<img src='"+src+"' style='"+(width>height ? "width:"+width+"px;" : "height:"+height+"px;")+"'><br><div class='tc_dialog_title'>"+o.title+"<br></div>");
                    });
                }else{
                    $(this).css({
                        width:(width),
                        height:(height)
                    });
                    $(this).find(".tc_dialog_content").html("<img src='"+src+"' style='"+(width>height ? "width:"+width+"px;" : "height:"+height+"px;")+"'><br><div class='tc_dialog_title'>"+o.title+"<br></div>");
                }
            });
        }
    };
    function repos(){
        var height = getScreen().height;
        var width = getScreen().width;
        var left = (getScreen().width / 2) - ($dialog.width() / 2);
        var top = (getScreen().height / 2) - ($dialog.height() / 2);
        if (navigator.platform == 'iPad' || navigator.platform == 'iPhone' || navigator.platform == 'iPod') {
            top = (window.innerHeight + window.pageYOffset) - $dialog.height();
        }
        if(options.openMode!='mouseFollow'){
            $bg.each(function(){
                $(this).css({
                    height:height,
                    width:width
                });
            });
        }
        $dialog.each(function(){
            $(this).css({
                left:left,
                top:top
            });
        });
    };
    
    function hideElements(){
        if(options.hideElementsThatCanTakePriority)
            $('embed, object, select').css({ 'visibility' : 'hidden' });
    };
    if(options.type=='image'){    
        $(object).each(function(){
            var tag = this.nodeName;
            var src = $(this).attr((tag=="A" ? "href" : ($(this).attr("url")!=undefined ? "url" : "src")));
            if(options.preloadAllImagesBeforeLoading){
                img = new Image();
                img.src = src;
            }
            var title = $(this).attr("title")!=undefined ? $(this).attr("title") : "";
            switch(options.openMode){
                case "click":
                    $(this).click(function(){
                        hideElements();
                        dialog({src:src,title:title,element:this});
                        return false;
                    });
                    break;
                case "mouseFollow":
                    $(this).mouseenter(function(e){
                        hideElements();
                        dialog({src:src,title:title,element:this});
                        var img = new Image();
                        img.src = src;
                        var realWidth = img.width;
                        var realHeight = img.height;
                        
                        $(document).bind('mousemove',function(e){
                            var allowedHeight = parseInt(realHeight > options.imageMaxHeight ? options.imageMaxHeight : realHeight);
                            var offset = parseInt(e.pageY) + allowedHeight;
                            var windowHeight = window.innerHeight - 50;
                            var top = parseInt((offset>windowHeight ? ((e.pageY > allowedHeight ? e.pageY - allowedHeight : allowedHeight - e.pageY)) : (e.pageY + 10)));
                            if(options.debug)
                                $('#debug').html("top="+top+", realHeight="+realHeight+", realWidth="+realWidth+", allowedHeight="+allowedHeight+", pageY="+e.pageY+", pageX="+e.pageX+", offset="+offset+", windowHeight="+windowHeight);
                            if(options.mouseFollowAlign=='right'){
                                var left = e.pageX + 10;
                                $dialog.css({
                                    left:left,
                                    top:top
                                });
                            }else{
                                var left = (e.pageX - (realWidth>options.imageMaxWidth ? options.imageMaxWidth : realWidth)) - 40 - parseInt(options.dialogContainerPadding) - parseInt(options.dialogContainerBorderSize);
                                $dialog.css({
                                    left:left,
                                    top:top
                                });
                            }
                        });
                    }).mouseleave(function(){
                        dialogRemove();
                    });
                    break;
            }
            $(this).css({cursor:"pointer"});
        });
    }
    if(options.type=='dialog'){
        hideElements();
        dialog({element:this});
    }
}