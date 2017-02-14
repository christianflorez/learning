var colors = {
    /*
    List of color schemes; Generated from https://coolors.co
    */
    0: {
        "background": "#B6C197",
        "container": "#D5DDBC",
        "font": "#000",
    },
    1: {
        "background": "#F1A208",
        "container": "#D5C67A",
        "font": "#000",
    },
    2: {
        "background": "#005377",
        "container": "#052F5F",
        "font": "#FFF",
    },
    3: {
        "background": "#D77A61",
        "container": "#D8B4A0",
        "font": "#000",
    },
    4: {
        "background": "#CFB3CD",
        "container": "#DFC2F2",
        "font": "#000",
    },
    5: {
        "background": "#1B263B",
        "container": "#0D1B2A",
        "font": "#FFF",
    },
    6: {
        "background": "#87255B",
        "container": "#B370B0",
        "font": "#000",
    },
    7: {
        "background": "#B02E0C",
        "container": "#EB4511",
        "font": "#000",
    },
    8: {
        "background": "#F3C969",
        "container": "#EDFF86",
        "font": "#000",
    },
    9: {
        "background": "#004BA8",
        "container": "#3E78B2",
        "font": "#000",
    },
    10: {
        "background": "#586F7C",
        "container": "#2F4550",
        "font": "#FFF",
    },
}

$(function(){
    // Populates HTML with initial data
    $.getJSON("http://api.forismatic.com/api/1.0/?method=getQuote&key=457653&format=jsonp&lang=en&jsonp=?")
    .done(newQuote)
    .fail(errorMessage)

    // Updates HTML with new quote when "#get-quote" button is clicked
    // This queries the Forismatic API, which returns a new quote everytime it's queried using the parameters included below
    // for more information, see the following link: http://forismatic.com/en/api/
    $("#get-quote").click( function() {
        $.getJSON("http://api.forismatic.com/api/1.0/?method=getQuote&key=457653&format=jsonp&lang=en&jsonp=?")
        .done(newQuote)
        .fail(errorMessage)
    });

    // Also updates HTML by pressing spacebar
    // http://stackoverflow.com/questions/6199038/javascript-event-triggered-by-pressing-space
    $(window).keypress(function (e) {
        if (e.keyCode === 0 || e.keyCode === 32) {
            e.preventDefault()
            $.getJSON("http://api.forismatic.com/api/1.0/?method=getQuote&key=457653&format=jsonp&lang=en&jsonp=?")
            .done(newQuote)
            .fail(errorMessage)
        }
    })
});

function newQuote (data, textStatus, jqXHR) {
    $("#quote").html(data.quoteText);
    $("#quote-author").html("by " + data.quoteAuthor);
    $("#quote-link").html("<a href='" + data.quoteLink + "'>Source</a>");

    // Dynamically builds tweet functionality
    $("#tweet-link").html("<a href='https://twitter.com/intent/tweet?hashtags=quotes&text=" + data.quoteText + " -" + data.quoteAuthor + "'>" + "<i class='fa fa-twitter fa-4x' aria-hidden='true'></i></a>");
    
    changeColors();
}

function errorMessage (jqXHR, textStatus, errorThrown) {
    // Logs error to browser's console
    console.log(errorThrown.toString());
}

// Animates changes in CSS properties
function changeColors () {
    var seed = parseInt(Math.random() * 10);
    $(".jumbotron-fluid, .btn").animate({
        backgroundColor: colors[seed]["background"]
        }, 1000
    );
    $(".container").animate({
        backgroundColor: colors[seed]["container"]
        }, 1000
    );
    $("p, blockquote footer, .btn, a:link, a:visited, a:hover, a:active, a").animate({
        color: colors[seed]["font"]
        }, 1000
    );   
}