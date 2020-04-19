let title = document.getElementsByClassName("title");
let resultDiv = null;
let result = 0
//let checkboxes = [];

// **Generate checkboxes.**
for( let i=0; i< title.length; i++){
    let checkbox  = document.createElement("INPUT");
    checkbox.setAttribute("type", "checkbox");
    title[i].appendChild(checkbox);
    //checkboxes[i] = checkbox;
    // I want to store the reference of checkboxes for later use. But it did't work.
}

// **called when magic button clicked.**
function calculate(){
    for( let i=title.length-1; i>=0 ; i-- ){
        if(title[i].childNodes[1].checked)  result += 1;
        result *= 2;
    }
    result /= 2;

    // initial result text or update result if existed,
    if( resultDiv == null ){
        resultDiv = document.createElement("div");
        resultDiv.className = "result";
        let resultText = document.createTextNode("I guess the number is " + result.toString() + ". Why so easy?");

        resultDiv.appendChild(resultText);
        root[1].appendChild(resultDiv);
    }
    else{
        resultDiv.childNodes[0].data = "I guess the number is " + result.toString() + ". Why so easy?";
    }

    console.log("result calculated");
    result = 0;
}
