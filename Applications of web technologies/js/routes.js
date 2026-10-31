/*
 * routes definition and handling for paramHashRouter
 */

import Mustache from "./mustache.js";
import processOpnFrmData from "./addOpinion.js";
import articleFormsHandler from "./articleFormsHandler.js";

//an array, defining the routes
export default[

    {
        //the part after '#' in the url (so-called fragment):
        hash:"welcome",
        ///id of the target html element:
        target:"router-view",
        //the function that returns content to be rendered to the target html element:
        getTemplate:(targetElm) =>
            document.getElementById(targetElm).innerHTML = document.getElementById("template-welcome").innerHTML
    },
    {
        hash:"articles",
        target:"router-view",
        getTemplate: fetchAndDisplayArticles
    },
    {
        hash:"opinions",
        target:"router-view",
       getTemplate: createHtml4opinions
    },
   {
        hash:"addOpinion",
       target:"router-view",
       getTemplate: (targetElm) =>{
            document.getElementById(targetElm).innerHTML = document.getElementById("template-addOpinion").innerHTML;
           document.getElementById("opnFrm").onsubmit=processOpnFrmData;

       }
    },
    {
        hash: "opinions",
        target: "router-view",
        getTemplate: createHtml4opinions,
    },
    {
        hash: "addOpinion",
        target: "router-view",
        getTemplate: (targetElm) => {
            const template = document.getElementById("template-addOpinion").innerHTML;
            document.getElementById(targetElm).innerHTML = template;

            // Подключаем обработчик формы
            const feedbackForm = document.getElementById("opnFrm");
            feedbackForm.onsubmit = processOpnFrmData;
        },
    },

    {
        hash:"article",
        target:"router-view",
        getTemplate: fetchAndDisplayArticleDetail
    },
    {
        hash:"artEdit",
        target:"router-view",
        getTemplate: editArticle
    },
    {
        hash: "artDelete",
        target: "router-view",
        getTemplate: deleteArticle,
    },
    {
        hash: "artInsert",
        target: "router-view",
        getTemplate: addArticle
    },
    {
        hash: "show",
        target: "router-view",
        getTemplate: openForm
    },
    {
        hash: "canselComm",
        target: "router-view",
        getTemplate: closeForm
    },
    {
        hash: "addComment",
        target: "router-view",
        getTemplate: postComment
    },
    {
        hash: "comments",
        target: "router-view",
        getTemplate: displayComments
    },
    {
        hash: "findArtbyTag",
        target: "router-view",
        getTemplate: findByTag
    },
];
/*
function createHtml4opinions(targetElm){
    const opinionsFromStorage=localStorage.myTreesComments;
    let opinions=[];

    if(opinionsFromStorage){
        opinions=JSON.parse(opinionsFromStorage);
        opinions.forEach(opinion => {
            opinion.created = (new Date(opinion.created)).toDateString();
            opinion.willReturn = opinion.willReturn?"I will return to this page.":"Sorry, one visit was enough.";
        });
    }

    document.getElementById(targetElm).innerHTML = Mustache.render(
        document.getElementById("template-opinions").innerHTML,
        opinions
    );
}
*/
/*function fetchAndDisplayArticles(targetElm, offsetFromHash = 0, totalCountFromHash = 0) {

    const offset = Number(offsetFromHash);
    const totalCount = Number(totalCountFromHash);

    // Если totalCount не задано, мы запросим только метаданные
    const fetchTotalCount = totalCount === 0;

    // URL для запроса статей
    const url = `${urlBase}/article?offset=${offset}&max=${articlesPerPage}`;

    function reqListener() {
        if (this.status == 200) {
            const responseJSON = JSON.parse(this.responseText);

            // Если мы запросили totalCount, обновляем его из meta
            const updatedTotalCount = fetchTotalCount ? responseJSON.meta.totalCount : totalCount;

            addArtDetailLink2ResponseJson(responseJSON);

            // Добавляем параметры для пагинации
            responseJSON.hasPrevious = offset > 0;
            responseJSON.previousOffset = Math.max(offset - articlesPerPage, 0);
            responseJSON.hasNext = offset + articlesPerPage < updatedTotalCount;
            responseJSON.nextOffset = offset + articlesPerPage;
            responseJSON.totalCount = updatedTotalCount;

            // Отображение статей с кнопками
            document.getElementById(targetElm).innerHTML =
                Mustache.render(
                    document.getElementById("template-articles").innerHTML,
                    responseJSON
                );

        } else {
            const errMsgObj = { errMessage: this.responseText };
            document.getElementById(targetElm).innerHTML =
                Mustache.render(
                    document.getElementById("template-articles-error").innerHTML,
                    errMsgObj
                );
        }
    }



    // Выполняем запрос
    var ajax = new XMLHttpRequest();
    ajax.addEventListener("load", reqListener);
    ajax.open("GET", url, true);
    ajax.send();
}
*/
/*
function fetchAndDisplayArticles(targetElm, offsetFromHash, totalCountFromHash) {
    const offset = Number(offsetFromHash);
    const totalCount = Number(totalCountFromHash);

    let urlQuery;

    if (offset && totalCount) {
        //napis tu tag piska
        const newOffset = offset * articlesPerPage; // тут вичислєм новиий і бам пум слей работає
        urlQuery = `?offset=${newOffset}&max=${articlesPerPage}`;

    } else {
        urlQuery = `?max=${articlesPerPage}`;
    }

    const url = `${urlBase}/article/${urlQuery}`;

    function reqListener() {
        if (this.status === 200) {
            const responseJSON = JSON.parse(this.responseText);
            addArtDetailLink2ResponseJson(responseJSON);


            responseJSON.articles.forEach(article => {
                // запрос
                const articleUrl = `${urlBase}/article/${article.id}`;
                let articleRequest = new XMLHttpRequest();
                articleRequest.addEventListener("load", function () {
                    if (this.status === 200) {
                        const articleBody = JSON.parse(this.responseText).content;


                        article.content = articleBody;

                        //все статьи
                        document.getElementById(targetElm).innerHTML =
                            Mustache.render(
                                document.getElementById("template-articles").innerHTML,
                                responseJSON
                            );
                    } else {
                        const errMsgObj = { errMessage: this.responseText };
                        document.getElementById(targetElm).innerHTML =
                            Mustache.render(
                                document.getElementById("template-articles-error").innerHTML,
                                errMsgObj
                            );
                    }
                });

                articleRequest.open("GET", articleUrl, true);
                articleRequest.send();
            });
        } else {
            const errMsgObj = { errMessage: this.responseText };
            document.getElementById(targetElm).innerHTML =
                Mustache.render(
                    document.getElementById("template-articles-error").innerHTML,
                    errMsgObj
                );
        }
    }

    console.log(url);
    let ajax = new XMLHttpRequest();
    ajax.addEventListener("load", reqListener);
    ajax.open("GET", url, true);
    ajax.send();
}
*/
function fetchAndDisplayArticles(targetElm, offsetFromHash = 0, totalCountFromHash = 0) {
    const offset = Number(offsetFromHash);
    const totalCount = Number(totalCountFromHash);
    const fetchTotalCount = totalCount === 0; // Если totalCount не задан, запрашиваем только метаданные
    const urlQuery = `?offset=${offset}&max=${articlesPerPage}`;
    const url = `${urlBase}/article/${urlQuery}`;

    function reqListener() {
        if (this.status === 200) {
            const responseJSON = JSON.parse(this.responseText);

            // Обновляем totalCount, если он ещё не был задан
            const updatedTotalCount = fetchTotalCount ? responseJSON.meta.totalCount : totalCount;

            addArtDetailLink2ResponseJson(responseJSON);

            // Настройка для пагинации
            responseJSON.hasPrevious = offset > 0;
            responseJSON.previousOffset = Math.max(offset - articlesPerPage, 0);
            responseJSON.hasNext = offset + articlesPerPage < updatedTotalCount;
            responseJSON.nextOffset = offset + articlesPerPage;
            responseJSON.totalCount = updatedTotalCount;

            // Загружаем содержимое статей
            let articlesProcessed = 0; // Счётчик для завершения обработки статей
            responseJSON.articles.forEach(article => {
                const articleUrl = `${urlBase}/article/${article.id}`;
                const articleRequest = new XMLHttpRequest();
                articleRequest.addEventListener("load", function () {
                    if (this.status === 200) {
                        // Добавляем содержимое статьи
                        article.content = JSON.parse(this.responseText).content;
                    } else {
                        article.content = "Failed to load article content.";
                    }

                    articlesProcessed++;
                    if (articlesProcessed === responseJSON.articles.length) {
                        // Когда все статьи обработаны, отображаем результат
                        document.getElementById(targetElm).innerHTML =
                            Mustache.render(
                                document.getElementById("template-articles").innerHTML,
                                responseJSON
                            );
                    }
                });

                articleRequest.open("GET", articleUrl, true);
                articleRequest.send();
            });

            // Если статей нет, отображаем результат сразу
            if (responseJSON.articles.length === 0) {
                document.getElementById(targetElm).innerHTML =
                    Mustache.render(
                        document.getElementById("template-articles").innerHTML,
                        responseJSON
                    );
            }
        } else {
            const errMsgObj = { errMessage: this.responseText };
            document.getElementById(targetElm).innerHTML =
                Mustache.render(
                    document.getElementById("template-articles-error").innerHTML,
                    errMsgObj
                );
        }
    }

    // Выполняем запрос на загрузку статей
    const ajax = new XMLHttpRequest();
    ajax.addEventListener("load", reqListener);
    ajax.open("GET", url, true);
    ajax.send();
}

function addArtDetailLink2ResponseJson(responseJSON){
    responseJSON.articles = responseJSON.articles.map(
        article =>(
            {
                ...article,
                detailLink:`#article/${article.id}/${responseJSON.meta.offset}/${responseJSON.meta.totalCount}`
            }
        )
    );
}

const urlBase = "https://wt.kpi.fei.tuke.sk/api";
const articlesPerPage = 20;

function fetchAndDisplayArticleDetail(targetElm,artIdFromHash,offsetFromHash,totalCountFromHash) {
    fetchAndProcessArticle(...arguments,false);
}
function fetchAndProcessArticle(targetElm,artIdFromHash,offsetFromHash,totalCountFromHash,forEdit){
    const url = `${urlBase}/article/${artIdFromHash}`;

    function reqListener () {
        // stiahnuty text
        console.log(this.responseText)
        if (this.status == 200) {
            const responseJSON = JSON.parse(this.responseText)
            if(forEdit){
                responseJSON.formTitle="Article Edit";
                responseJSON.submitBtTitle="Save article";
                responseJSON.backLink=`#article/${artIdFromHash}/${offsetFromHash}/${totalCountFromHash}`;

                document.getElementById(targetElm).innerHTML =
                    Mustache.render(
                        document.getElementById("template-article-form").innerHTML,
                        responseJSON
                    );
                if(!window.artFrmHandler){
                    window.artFrmHandler= new articleFormsHandler("https://wt.kpi.fei.tuke.sk/api");
                }
                window.artFrmHandler.assignFormAndArticle("articleForm","hiddenElm",artIdFromHash,offsetFromHash,totalCountFromHash);
            }else{

                responseJSON.backLink=`#articles/${offsetFromHash}/${totalCountFromHash}`;
                responseJSON.editLink=
                    `#artEdit/${responseJSON.id}/${offsetFromHash}/${totalCountFromHash}`;
                responseJSON.deleteLink=
                    `#artDelete/${responseJSON.id}/${offsetFromHash}/${totalCountFromHash}`;

                document.getElementById(targetElm).innerHTML =
                    Mustache.render(
                        document.getElementById("template-article").innerHTML,
                        responseJSON
                    );
            }
        } else {
            const errMsgObj = {errMessage:this.responseText};
            document.getElementById(targetElm).innerHTML =
                Mustache.render(
                    document.getElementById("template-articles-error").innerHTML,
                    errMsgObj
                );
        }

    }

    console.log(url)
    var ajax = new XMLHttpRequest();
    ajax.addEventListener("load", reqListener);
    ajax.open("GET", url, true);
    ajax.send();
}

function editArticle(targetElm, artIdFromHash, offsetFromHash, totalCountFromHash) {
    fetchAndProcessArticle(...arguments,true);
}
function deleteArticle(targetElm, artIdFromHash, offsetFromHash = 0, totalCountFromHash = 0) {
    const url = `${urlBase}/article/${artIdFromHash}`;

    function reqListener() {
        if (this.status === 200 || this.status === 204) {
            console.log("Article deleted successfully.");

            // Обновляем отображение после удаления
            fetchAndDisplayArticles(targetElm, offsetFromHash, totalCountFromHash);
        } else {
            const errMsgObj = { errMessage: this.responseText || "Failed to delete article." };
            document.getElementById(targetElm).innerHTML =
                Mustache.render(
                    document.getElementById("template-articles-error").innerHTML,
                    errMsgObj
                );
        }
    }

    function reqError() {
        const errMsgObj = { errMessage: "Network error occurred during deletion." };
        document.getElementById(targetElm).innerHTML =
            Mustache.render(
                document.getElementById("template-articles-error").innerHTML,
                errMsgObj
            );
    }

    // Выполняем DELETE-запрос
    const ajax = new XMLHttpRequest();
    ajax.addEventListener("load", reqListener);
    ajax.addEventListener("error", reqError);
    ajax.open("DELETE", url, true);
    ajax.send();
}
function addArticle(targetElm) {
    const url = `${urlBase}/article/`;

    // Функция обработки отправки формы
    function submitArticle(event) {
        event.preventDefault(); // Предотвращаем перезагрузку страницы

        const formData = new FormData(event.target); // Собираем данные формы
        const articleData = Object.fromEntries(formData.entries()); // Преобразуем в объект

        const xhr = new XMLHttpRequest();
        xhr.open("POST", url, true);
        xhr.setRequestHeader("Content-Type", "application/json");

        xhr.onload = function () {
            if (xhr.status === 201) {
                console.log("Article added successfully.");
                const createdArticle = JSON.parse(xhr.responseText);
                // Перенаправляем пользователя на #welcome после успешного добавления
                location.hash = "#welcome"; // Перенаправление на #welcome
            } else {
                console.error("Failed to add article:", xhr.responseText);
                const errMsgObj = { errMessage: xhr.responseText };
                document.getElementById(targetElm).innerHTML =
                    Mustache.render(
                        document.getElementById("template-articles-error").innerHTML,
                        errMsgObj
                    );
            }
        };

        xhr.onerror = function () {
            console.error("Network error occurred while adding article.");
        };

        xhr.send(JSON.stringify(articleData)); // Отправляем данные в JSON формате
    }

    // Отображение формы для добавления статьи
    const responseJSON = {
        formTitle: "Add New Article",
        submitBtTitle: "Save Article",
        backLink: "#welcome" // Возвращаем на #welcome
    };

    document.getElementById(targetElm).innerHTML =
        Mustache.render(
            document.getElementById("template-article-form").innerHTML,
            responseJSON
        );

    // Назначаем обработчик отправки формы
    const form = document.getElementById("articleForm");
    if (form) {
        form.onsubmit = submitArticle;
    } else {
        console.error("Form element not found.");
    }

    // Назначаем обработчик кнопки Back
    const backBtn = document.getElementById("backBtn"); // Убедитесь, что у вас есть элемент кнопки back в шаблоне
    if (backBtn) {
        backBtn.onclick = function () {
            location.hash = responseJSON.backLink; // Возвращаем на #welcome
        };
    } else {
        console.error("Back button not found.");
    }
}


function openForm() {
    const formWrap = document.getElementById('form-wrap');
    formWrap.style.display = 'block';  // Показываем форму
    const headerComm = document.getElementById('addComment');
    headerComm.style.display = 'none';  // Скрываем кнопку "Add Comment"
}
function closeForm() {
    const formWrap = document.getElementById('form-wrap');
    formWrap.style.display = 'none';  // Скрываем форму
    const headerComm = document.getElementById('addComment');
    headerComm.style.display = 'block';  // Показываем кнопку "Add Comment"
}
function displayComments(id, comOffsets) {
    const url = `${urlBase}/article/${id}/comment/?max=100&offset=${comOffsets}`;

    function comm() {
        if (this.status === 200) {
            const responseJSONComment = JSON.parse(this.responseText);
            const commentsContainer = document.querySelector('.article-form-screen--comments-container');
            commentsContainer.innerHTML = '';  // Очистить контейнер комментариев

            // Для каждого комментария формируем HTML
            responseJSONComment.comments.forEach(comment => {
                const commentElement = document.createElement('div');
                commentElement.classList.add('article-form-screen--comments');
                commentElement.innerHTML = `
                    <div class="article-form-screen--comments-info">
                        <h2>Author: ${comment.author}</h2>
                        <p>Comment: ${comment.text}</p>
                        <h3>Date: ${new Date(comment.dateCreated).toDateString()}</h3>
                    </div>
                `;
                commentsContainer.appendChild(commentElement);
            });
        } else {
            alert("Error responseJSONComment");
        }
    }

    const ajax = new XMLHttpRequest();
    ajax.addEventListener("load", comm);
    ajax.open("GET", url, true);  // Установить асинхронный режим
    ajax.send();
}
function postComment(event, artId, offsetFromHash) {
    event.preventDefault();

    const commentsData = {
        author: document.getElementById("author3").value.trim(),
        text: document.getElementById("title3").value.trim()
    };

    if (commentsData.text === "" || commentsData.author === "") {
        window.alert("Please, enter both your name and comment");
        return;
    }

    const postReqSettings = {
        method: 'POST',
        headers: {
            'Content-Type': 'application/json;charset=utf-8',
        },
        body: JSON.stringify(commentsData)
    };

    fetch(`${urlBase}/article/${artId}/comment`, postReqSettings)
        .then(() => {
            window.location.hash = `#article/${artId}/${offsetFromHash}`;
            closeForm();  // Закрыть форму после отправки комментария
            displayComments(artId, offsetFromHash);  // Обновить комментарии
        })
        .catch(error => {
            console.error('Error posting comment:', error);
            alert('Error posting comment');
        });
}

function findByTag(targetElm, artIdFromHash, offsetFromHash, totalCountFromHash) {
    let teg = document.getElementById("tag").value.trim();
    console.log(teg);
    let offset = 20 + counter * 20;
    const totalCount = Number(totalCountFromHash);
    let urlQuery = "";
    urlQuery = `?tag=${teg}&?offset=${offset}&max=${articlesPerPage}`;
    console.log(urlQuery);
    const url = `${urlBase}/article${urlQuery}`;

    function reqListener() {
        // stiahnuty text
        console.log(this.responseText)
        if (this.status == 200) {
            const responseJSON = JSON.parse(this.responseText)
            addArtDetailLink2ResponseJson(responseJSON);
            document.getElementById(targetElm).innerHTML =
                Mustache.render(
                    document.getElementById("template-articles").innerHTML,
                    responseJSON
                );
            const incrementCount = document.getElementById("increment-count");
            const decrementCount = document.getElementById("decrement-count");

            if (incrementCount && decrementCount) {
                incrementCount.addEventListener("click", () => {
                    if (counter != 0) {
                        counter--;
                    }
                    window.location.hash = "`#main/1/25/`";
                    window.location.hash = "`#main/1/25/`";
                });

                decrementCount.addEventListener("click", () => {
                    counter++;
                    window.location.hash = "`#main/1/25/`";
                    window.location.hash = "`#main/1/25/`";
                });
            }

        } else {
            const errMsgObj = { errMessage: this.responseText };
            document.getElementById(targetElm).innerHTML =
                Mustache.render(
                    document.getElementById("template-articles-error").innerHTML,
                    errMsgObj
                );
        }
    }

    console.log(url)
    var ajax = new XMLHttpRequest();
    ajax.addEventListener("load", reqListener);
    ajax.open("GET", url, true);
    ajax.send();
}

document.addEventListener("DOMContentLoaded", function () {
    const feedbackForm = document.getElementById("feedbackForm");

    // Загружаем сохраненные данные при загрузке страницы
    function loadFeedback() {
        const storedFeedback = JSON.parse(localStorage.getItem("feedbackData")) || [];
        renderFeedback(storedFeedback);
    }

    // Отображение отзывов
    function renderFeedback(feedbackList) {


        const template = document.getElementById("feedbackTemplate").innerHTML;
        const rendered = Mustache.render(template, { feedbackList });
        document.getElementById("feedbackList").innerHTML = rendered;

        // Добавление обработчика события для удаления
        const deleteButtons = document.querySelectorAll(".delete-feedback");
        deleteButtons.forEach(button => {
            button.addEventListener("click", function () {
                const index = button.getAttribute("data-index");
                deleteFeedback(index);
            });
        });
    }

    // Удаление отзыва
    function deleteFeedback(index) {
        const storedFeedback = JSON.parse(localStorage.getItem("feedbackData")) || [];
        storedFeedback.splice(index, 1);  // Удаление отзыва по индексу
        localStorage.setItem("feedbackData", JSON.stringify(storedFeedback));
        renderFeedback(storedFeedback); // Обновление отображения
    }

    // Обработчик события отправки формы
    feedbackForm.addEventListener("submit", function (event) {
        event.preventDefault();

        // Сбор данных из формы
        const formData = {
            name: document.getElementById("name").value.trim(),
            email: document.getElementById("email").value.trim(),
            keywords: document.getElementById("keywords").value.trim(),
            imageUrl: document.getElementById("image-url").value.trim(),
            opinion: document.querySelector("input[name='opinion']:checked")?.value,
            features: Array.from(
                document.querySelectorAll("input[name='features']:checked")
            ).map(input => input.value).join(", "),
            feedback: document.getElementById("feedback").value.trim(),
            created: new Date().toLocaleString() // форматируем дату
        };

        // Загружаем текущие отзывы из localStorage
        const storedFeedback = JSON.parse(localStorage.getItem("feedbackData")) || [];

        // Добавляем новый отзыв в начало списка
        storedFeedback.unshift(formData);

        // Сохраняем обновленный список отзывов в localStorage
        localStorage.setItem("feedbackData", JSON.stringify(storedFeedback));

        // Обновление отображения данных
        renderFeedback(storedFeedback);

        // Очистка формы
        feedbackForm.reset();
        alert("Vaše údaje boli úspešne odoslané!");
    });

    // Загружаем данные при инициализации страницы
    loadFeedback();
});

function createHtml4opinions(targetElm) {
    const opinionsFromStorage = localStorage.myTreesComments;
    let opinions = [];

    if (opinionsFromStorage) {
        opinions = JSON.parse(opinionsFromStorage).map((opinion, index) => ({
            ...opinion,
            index
        }));
    }

    document.getElementById(targetElm).innerHTML = Mustache.render(
        document.getElementById("template-opinions").innerHTML,
        opinions
    );

    setupDeleteOpinionHandlers();
}

function setupDeleteOpinionHandlers() {
    const deleteButtons = document.querySelectorAll(".delete-opinion");
    deleteButtons.forEach((button) => {
        button.addEventListener("click", function () {
            const index = this.getAttribute("data-index");
            deleteOpinion(index);
        });
    });
}

function deleteOpinion(index) {
    let opinions = JSON.parse(localStorage.myTreesComments || "[]");
    opinions.splice(index, 1);
    localStorage.myTreesComments = JSON.stringify(opinions);
    createHtml4opinions("router-view");
}
