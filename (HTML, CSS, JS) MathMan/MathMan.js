$(document).ready(function () {
    begin_animate(); //First Look animation
    //Functions called on the clicks of certain buttons
    $("#How-to").click(function () {
        howto_click();
    });
    $("#Back").click(function () {
        back_click();
    });
    $("#Play").click(function () {
        play_click();
        game();
    });
    $("#Play_Again").click(function () {
        reset();
        game();
    });
    $("#Bonus_Level").click(function () {
        reset();
        bonusgame();
    });
    $("#Play_Again2").click(function () {
        reset();
        bonusgame();
    });
});

var random_operator = [{
    operation: "+",
    result: function (a, b) {
        return a + b;
    }
}, {
    operation: "-",
    result: function (a, b) {
        return a - b;
    }
}, {
    operation: "*",
    result: function (a, b) {
        return a * b;
    }
}, {
    operation: "/",
    result: function (a, b) {
        return Math.round(a / b);
    }
}]; //Object to generate random operators and their results


function begin_animate() {
//Function that cause the beginning animation
    $("#title").animate({
        top: "+=100px"
    }, 2000);
    $("#How-to").animate({
        opacity: 1
    }, 2000);
    $("#Play").animate({
        opacity: 1
    }, 2000);
}

function play_click() {
//Funtion to make elements disappear on pressing "Begin" button
    $("#How-to").css("display", "none");
    $("#title").css("display", "none");
    $("#Play").css("display", "none");
}

function howto_click() {
//Funtion to make the How-To Play page appear
    $("#How-to").css("display", "none");
    $("#title").css("display", "none");
    $("#Play").css("display", "none");
    $("#Back").animate({
        opacity: 1
    }, 500);
    $("#rules").animate({
        opacity: 1
    }, 500);
    $("ol").css("display", "block");
    $("#gif2").css({display: "block"});
}

function back_click() {
//Function to respond to clicking the "Back" button in all case scenarios

    $("#How-to").css("display", "block");
    $("#title").css("display", "block");
    $("#Play").css("display", "block");
    $("#Back").animate({
        opacity: 0
    }, 200);
    $("#rules").animate({
        opacity: 0
    }, 200);
    $("ol").css("display", "none");
    reset();
}

String.prototype.replaceAt = function (index, character) {
    return this.substr(0, index) + character + this.substr(index + character.length);
}; //Appended onto class of type 'String' variable to return an ammended string

function reset() {
//Function that is called when a new page needs to appear. Hence, it turns off (or sets to default value) all relevant elements. The new page elements are displayed by their respective functions
    $("form").css("display", "none");
    $("#button2").css("display", "none");
    $("#equation").empty();
    $("#image").css("display", "none");
    $("#wentries").empty();
    $('#wentries').append("Wrong Entries:</br> ");
    $("#status").empty();
    $('#status').append("Status:</br><div id='misses'> 4 misses left </div>");
    $("form")[0].reset();
    $("#wentries").css("display", "none");
    $("#status").css("display", "none");
    $("#Play_Again").css({display: "none"});
    $("#Play_Again2").css({display: "none"});
    $("#Bonus_Level").css({display: "none"});

    $('#image').css({
        content: "url(http://s27.postimg.org/j7azh9skv/Paint_1_new.jpg)"
    });
    $("#notes").animate({
            opacity: 0
     }, 500);
    $("#gif1").css({display: "none"});
    $("#gif2").css({display: "none"});
}

function returndigits(number) {
    //Function that returns the digits of a number (upto 3 digits) in the form of an array
    if (getlength(number) === 1) return [0, (number % 10)];

    else if (getlength(number) === 2) return [Math.floor(number / 10), number % 10];

    else return [Math.floor(number / 100), Math.floor((number - (Math.floor(number / 100) * 100)) / 10), number % 10];

}

function getlength(number) {
    //Function that returns the number of digits in a number
    return number.toString().length;
}

function game() {
    //Function that navigates through the game
    var first_num = Math.floor(Math.random() * 100); //Generating the first random number
    var second_num = Math.floor(Math.random() * 100);
//Generating the second random number
    var sum = first_num + second_num;
    var list_new = []; //List to store all the digits of the equation
    var wrong_list = []; //List to store all the wrong entries
    var loss = 0; //Variable that will store the number of wrong entries
    var check = false; //Variable to check whether the game has been won of lost
    list_new = list_new.concat(returndigits(first_num));
    list_new = list_new.concat(returndigits(second_num));
    list_new = list_new.concat(returndigits(sum));
    var equation = "_ _ + _ _ ="; //A part of the default equation

    for (var i = 0; i < returndigits(sum).length; i++){//For loop to add on the blanks for the digits of sum
    equation = equation.concat(" _");
    }
    gamesetup(equation); //Function to setup all working elements in the game
    $('#button2').unbind("click").click(function () {//Function to respond to a click of the "Enter" button
        var toAdd = $('input[name=EntryForm]').val();
        if ((Number(toAdd) > -1 && Number(toAdd) < 10) && (toAdd !== " ")) {
            var old_equation = equation;
            equation = new_equation(equation, Number(toAdd), list_new);
            if (old_equation === equation) {
             //Response to a wrong entry
                loss++;
                wrong_list = wrong_list.concat(toAdd);
                //$("#image").remove();
                check = checkloss(loss, wrong_list);
                if (check === true){
                    $("#Play_Again").css("display", "block");


                }
            } else {
             //Response to a right entry
                $("#equation").empty();
                $("#equation").append("<div>" + equation + "</div>");
                check = checkvictory_game(equation);
                if (check === true){
                    $("#Play_Again").css({display: "block"});
                    $("#gif1").css({background: "url(http://i.imgur.com/Kvy1Jva.gif) no-repeat center center"});
                    $("#gif1").css("display", "block");
                }
            }
        } else {
            //Response to an input of a non single digit integer
            $("#int").animate({
                opacity: 1
            });
            $("#int").delay(1000);
            $("#int").animate({
                opacity: 0
            });
        }
    });
    return;
}

function gamesetup(equation) {
    //Function to make all the working elements of the game appear
    $("#equation").append("<div>" + equation + "</div>");
    $("#equation").animate({
        opacity: 1
    }, 500);
    $("#button2").css("display", "block");
    $("form").css("display", "block");
    $("#image").css("display", "block");
    $("#wentries").css("display", "block");
    $("#status").css("display", "block");
    $("#Back").animate({
        opacity: 1
    });
}


function checkvictory_game(equation) {
//Function to check whether or not a game has been won. It does so by counting the number of dashes left in the equation, and responds accordingly.
    var flash = 0;
    for (var i = 0; i < equation.length; i++)
    if (equation[i] === "_") flash++;
    if (flash === 0) {
        $("#status").empty();
        $("#status").append("Status:<br /><div id=win> You win. </div>");
        $("form").css("display", "none");
        $("#button2").css("display", "none");
        $("#Play_Again").css("display", "block");

        $("#Bonus_Level").css("display", "block");

        return true;
    }
    return false;
}

function checkvictory_bonusgame(equation) {
//Almost the same function as previous. The only difference is that the "Bonus Level" button doesn't need to appear at the end of the Bonus Game
    var flash = 0;
    for (var i = 0; i < equation.length; i++)
    if (equation[i] === "_") flash++;
    if (flash === 0) {
        $("#status").empty();
        $("#status").append("Status:<br /><div id=win> You win. </div>");
        $("form").css("display", "none");
        $("#button2").css("display", "none");
        $("#Play_Again").css("display", "block");
        return true;
    }
    return false;
}

function checkloss(loss, wrong_list) {
//Function to check whether or not the game has been lost. It also displays the hangman images, wrong entries and the status of the game.
//It checks for a loss and changes the wrong entries, status and hangman image by checking  the "loss" variable and responding accordingly.
    switch (loss) {
        case 1:
            $('#image').css({
                content: "url(http://s11.postimg.org/x1i4wqwr3/Paint_2_new.jpg)"
            });

            $("#wentries").empty();
            $('#wentries').append("Wrong Entries:<br /><div>" + wrong_list + "</div>");
            $("#status").empty();
            $("#status").append("Status:<br /><div id=misses> 3 misses left </div>");
            return false;
        case 2:
            $('#image').css({
                content: "url(http://s4.postimg.org/kqj1xm02x/Paint_3_new.jpg)"
            });

            $("#wentries").empty();
            $('#wentries').append("Wrong Entries:<br /><div>" + wrong_list + "</div>");
            $("#status").empty();
            $("#status").append("Status:<br /><div id=misses> 2 misses left </div>");
            return false;
        case 3:
            $('#image').css({
                content: "url(http://s13.postimg.org/ed6igvsn7/Paint_4_new.jpg)"
            });

            $("#wentries").empty();
            $('#wentries').append("Wrong Entries:<br /><div>" + wrong_list + "</div>");
            $("#status").empty();
            $("#status").append("Status:<br /><div id=misses> 1 miss left </div>");
            return false;

        case 4:
            $('#image').css({
                content: "url(http://s23.postimg.org/49f9g24fr/Paint_5_new.jpg)"
            });

            $("#wentries").empty();
            $('#wentries').append("Wrong Entries:<br /><div>" + wrong_list + "</div>");
            $("#status").empty();
            $("#status").append("Status:<br /><div id=loss> You lost. </div>");
            $("form").css("display", "none");
            $("#button2").css("display", "none");
            $("#gif1").css({background: "url(http://i.imgur.com/8nVqVr9.gif) no-repeat center center"});
            $("#gif1").css({display: "block"});
            return true;

    }
}


function new_equation(equation, number, list_new) {
//Function that returns a modified (or unmodified) equation upon entry by the user
    var index = [];
    var count = 0;
    for (var i = 0; i < list_new.length; i++){//To put position(s) of "number" in the equation in a list called "index"
        if (list_new[i] === number) index.push(i + 1);}

    for (i = 0; i < equation.length; i++) {
        if (equation[i] === "_" || (Number(equation[i]) > -1 && Number(equation[i]) < 10) && (equation[i] !== " ")) {
            count++;
            if (($.inArray(count, index)) > -1) {//Changing equation with the help the earlier change in 'String' Object
                equation = equation.replaceAt(i, number.toString());
            }

        }
    }
    return equation;
}

function bonusgame() {
//Function to navigate through the Bonus Level
    $("#Bonus_Level").animate({
            opacity: 0
        }, 500);
    $("#notes").animate({
            opacity: 1
        }, 500);

    var first_num = Math.floor(Math.random() * 10); //Generating a random value b/w 0 and 10.
    if (first_num === 0){ //Avoiding the value 0 as division with zero leads to an underfined answer
        first_num = 1;
    }
    var second_num = Math.floor(Math.random() * 10);
    if (second_num === 0){
        second_num = 1;
    }
    var random_num1 = Math.floor(Math.random() * 4); //Generating random operator
    var operation1 = random_operator[random_num1].operation; //Generating random operator
    var third_num = Math.floor(Math.random() * 10);
    if (third_num === 0){
        third_num = 1;
    }
    var random_num2 = Math.floor(Math.random() * 4);
    var operation2 = random_operator[random_num2].operation;
    var result2 = Math.abs(calculate_result(first_num, second_num, third_num, random_num1, random_num2, operation1, operation2)); //Calculating result of generated equation according to the BODMAS rule using the function calculate_result. It's absolute value is taken to avoid the inconvienience of a negative number
    var list_new = []; // List to store digits of a generated numbers and result
    var wrong_list = []; // List to store wrong entries
    var loss = 0; //Variable to store number of losses
    var check = false; //Variable to check whether or not the game has been won or lost
    list_new = list_new.concat(returndigits(first_num));
    list_new = list_new.concat(returndigits(second_num));
    list_new = list_new.concat(returndigits(third_num));
    list_new = list_new.concat(returndigits(result2));
    var equation = "_ _ " + operation1 + " _ _ " + operation2 + " _ _ " + " ="; //Generating default equation for the system generated
    for (var i = 0; i < returndigits(result2).length; i++){// Adding number of blanks to the default equation
    equation = equation.concat(" _");
    }
    gamesetup(equation); //setting up basic elements on the screen for the game
    $('#button2').unbind("click").click(function () {//Function to respond to user input
        var toAdd = $('input[name=EntryForm]').val();
        if ((Number(toAdd) > -1 && Number(toAdd) < 10) && (toAdd !== " ")) {
            var old_equation = equation;
            equation = new_equation(equation, Number(toAdd), list_new);
            if (old_equation === equation) {
                //Response to a wrong input entry
                loss++;
                wrong_list = wrong_list.concat(toAdd);
                //$("#image").remove();
                check = checkloss(loss, wrong_list);
                if (check === true){
                    $("#Play_Again2").css({display: "block"});
                }
            } else {
                //Response to a right input entry
                $("#equation").empty();
                $("#equation").append("<div>" + equation + "</div>");
                check = checkvictory_bonusgame(equation);
                if (check === true){
                    $("#Play_Again2").css({display: "block"});
$("#gif1").css({background: "url(http://i.imgur.com/Kvy1Jva.gif) no-repeat center center"});
                    $("#gif1").css("display", "block");
                }
            }
        } else {
            //Response to non-single digit integer value entry
            $("#int").animate({
                opacity: 1
            });
            $("#int").delay(1000);
            $("#int").animate({
                opacity: 0
            });
        }
    });
    return;
}

function calculate_result(first_num, second_num, third_num, random_num1, random_num2, operation1, operation2) {
    //Function to calculate the result of rnadomly generated equation using BODMAS
    var temp1_rs;
    var result;
    if (operation1 === "*" || operation1 === "/") {
        temp1_rs = random_operator[random_num1].result(first_num, second_num);
        result = random_operator[random_num2].result(temp1_rs, third_num);
        return result;
    } else if (operation2 === "*" || operation2 === "/") {
        temp1_rs = random_operator[random_num2].result(second_num, third_num);
        result = random_operator[random_num1].result(temp1_rs, first_num);
        return result;
    }
    else {
        temp1_rs = random_operator[random_num1].result(first_num, second_num);
        result = random_operator[random_num2].result(temp1_rs, third_num);
        return result;
    }
}
