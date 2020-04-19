// **Generate Data**
let MaxNumber = 63;
let CardData = [];
for (let v=0; v<6; v++){
    CardData[v] = [];
}
//a simple bit checking to push numbers into right cards.
for (let i = 0b1; i <= MaxNumber; i++) {
    if( (i & 0b1) == 0b1)           CardData[0].push(i.toString());
    if( (i & 0b10) == 0b10)         CardData[1].push(i.toString());
    if( (i & 0b100) == 0b100)       CardData[2].push(i.toString());
    if( (i & 0b1000) == 0b1000)     CardData[3].push(i.toString());
    if( (i & 0b10000) == 0b10000)   CardData[4].push(i.toString());
    if( (i & 0b100000) == 0b100000) CardData[5].push(i.toString());
}

// **Generate grid**
let root = document.getElementsByClassName("root");

for (let i=0; i<6; i++){

    let card = document.createElement("div");
    card.className = "card";

    let title = document.createElement("div");
    title.className = "title";

    let titleContent = document.createTextNode('第'+ (i+1).toString() + '張卡片');
    title.appendChild(titleContent);
    card.appendChild(title);

    for(let j=0; j<CardData[i].length; j++){
        let number = document.createElement("div");
        let numberContent = document.createTextNode(CardData[i][j]);
        number.appendChild(numberContent);
        card.appendChild(number);
    }

    root[0].appendChild(card);
}
