  $(document).ready(function(){
  // this is for adding smooth scroll when clicking on hyperlinks
    $(document).on('click', 'a', function(event){
        event.preventDefault();

        $('html, body').animate({
            scrollTop: $( $.attr(this, 'href') ).offset().top -45
        }, 500);
    });
    // this is for adding navbar active states
    $(".nav a").on("click", function(){
       $(".nav").find(".active").removeClass("active");
       $(this).parent().addClass("active");
    });
  });
