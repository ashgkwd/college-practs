var $ = document.querySelector.bind(document);

window.onload = function () {
  var iText = $('#query');
  iText.addEventListener('keydown', function (e) {
    if (e.keyCode==13 && iText.validity.valid && $('#loading').style.visibility=='hidden') {
      $('#loading').style.visibility = 'visible';

      // get result
      var fd = new FormData();
      fd.append('action', 'search');
      fd.append('query', iText.value);
      apiCall(fd, displayResult);
    }
  });

  var displayResult = function (r) {
    var list = JSON.parse(r.target.response);
    console.log(list);
    var dom = $('#results');
    dom.innerHTML = "";
    $('#loading').style.visibility = 'hidden';
    var adminOptions = ($('#book-title'))?true:false;

    if (list.length === 0) {
      dom.innerHTML = "No Results Found! Try Again";
    } else {
      for (var i = list.length - 1; i >= 0; i--) {
        var a = list[i];
        var newDiv = document.createElement('div');
        if (adminOptions) {
          adminOptions = '<span class="c-remove" data-bookid="'+a.id+'" onclick="removeBook(this);"> &times;</span>';
        } else {
          adminOptions = "";
        }
        newDiv.innerHTML = '<section class="ag-card" data-bookid="'+a.id+'">'+'<h1 class="c-title">'+a.title+'</h1>'+'<p class="c-author">by '+a.author+'</p>'+'<p class="c-box">'+adminOptions+'<a class="c-link" href="'+a.download+'" target="_blank"> Link </a>'+'<span class="c-publication">'+a.publication+' publication</span>'+'</p>'+'</section>';
        dom.appendChild(newDiv);
      }
    }
  };

  // Admin spesific functions
  if ($('#book-title')) {
    var title = $('#book-title');
    var author = $('#book-author');
    var publication = $('#book-publication');
    var url = $('#book-link');
    url.addEventListener('keydown', function(e) {
      if (e.keyCode==13) {
        if (title.validity.valid && author.validity.valid && publication.validity.valid && url.validity.valid) {
          var fd = new FormData();
          fd.append('action', 'add');
          fd.append('title', title.value);
          fd.append('author', author.value);
          fd.append('publication', publication.value);
          fd.append('download', url.value);
          apiCall(fd, setMessage);
        } else {
          displayMessage("Fill All The Fields Properly");
        }
      }
    });
  }

  var setMessage = function (r) {
    if (JSON.parse(r.target.response).status=='success') {
      displayMessage('Book Added To Database. Cheers!');
    }
  };

  var displayMessage = function (s) {
    var m = $('#message');
    m.innerHTML = s;
    m.style.visibility = 'visible';
    setTimeout(function(){
      m.style.visibility = 'hidden';
    }, 6000);
  };
};

var removeBook = function (e) {
    console.info(e.dataset.bookid);
    var fd = new FormData();
    fd.append('action', 'remove');
    fd.append('bookid', e.dataset.bookid);
    apiCall(fd, function (r) {
      if (JSON.parse(r.target.response).status=='success') {
        var removed = $('.ag-card[data-bookid="'+e.dataset.bookid+'"]');
        removed.innerHTML = "This book is removed from database.";
        setTimeout(function () {
          removed.innerHTML = "";
          removed.classList.remove('ag-card');
        }, 4000);
      }
    });
  };

var apiCall = function (d, c) {
    var xhr = new XMLHttpRequest();
    xhr.onload = c;
    xhr.open("POST", "/api.php");
    xhr.send(d);
  };