
$(document).ready(function() {
  generate_tutorials();
});

// POPULAR TUTORIALS CAROUSEL
function generate_tutorials() {
  $.ajax({
    url: 'https://smileschool-api.hbtn.info/popular-tutorials',
    type: 'GET',
    success: function(data) {
      let cards = '';
      data.forEach((item, index) => {
        $('#popular-card').append(`
          <div class="h-100 col-12 col-sm-6 col-md-4 card-deck">
            <div class="card border-0 d-flex flex-column">

              <div class="card-img-top">
                <img src="${item.thumb_url}" class="card-img-top" alt="${item.title}">
                <img src="images/play.png" alt="Play Button" class="play-button">
              </div>

              <div class="card-body px-2">
                <h5 class="card-title">${item.title}</h5>
                <p class="card-text">${item['sub-title']}</p>
              </div>

              <class='card-footer' style="flex:1;">
                <div class="row">
                  <img src="${item.author_pic_url}" alt="tiny profile" style="height: 20px;" class="ml-4 mr-3 rounded-circle">
                  <h6 class="purple">${item.author}</h6>
                </div>
                <div class="row ml-2 mr-0">
                ${(function stars() {
                  let stars = '';
                  for (let i = 1; i <= 5; i++)
                  {
                    if (i < item.star) {
                      stars += `<img src="./images/star_on.png" height="15px" width="15px">`
                    } else {
                      stars += `<img src="./images/star_off.png" height="15px" width="15px">`
                    }
                  }
                  return stars;
                })
                ()}
                <p class='ml-auto mr-3 purple'>${item.duration}</p>
              </div>
            </div>
          </div>
          `);
      });
      $('#popular-card').slick({
        slidesToShow: 4,
        slidesToScroll: 1,
        responsive: [
          {
            breakpoint: 768,
            settings: {
              slidesToShow: 2
            }
          },
          {
            breakpoint: 576,
            settings: {
              slidesToShow: 1
            }
          }
        ]
      });

      // remove loader and show carousel
      $('#popular-loader').remove();
      // $('#popular-card').removeClass('d-none');
      resizeCards();
    }
  });
};

function resizeCards() {
  console.log("resizing...");
  let maxHeight = 0;
  let cardBodies = document.querySelectorAll('.card-body');
  cardBodies.forEach(function(cardBody) {
    cardBody.style.height = 'auto';
    maxHeight = Math.max(maxHeight, cardBody.offsetHeight);
  });
  cardBodies.forEach(function(cardBody) {
    cardBody.style.height = maxHeight + 'px';
  });
}

window.addEventListener('resize', resizeCards);
window.dispatchEvent(new Event('resize'));
