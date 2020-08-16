// constructor
function book(title, auther, year) {
  this.title = title;
  this.auther = auther;
  this.year = year;
}

//get summary
book.prototype.getSummary = function() {
  return `${this.title} is written by ${this.auther} in ${this.year}`;
};

//get age
book.prototype.getAge = function() {
  return `this book is ${2020 - this.year} old`;
};

//revise info
book.prototype.revise = function(newYear) {
  this.year = newYear;
};

//instantiate
const book1 = new book("wht's up yo", "me la", "1895");
console.log(book1.getAge());
book1.revise(123);
console.log(book1.getAge());

//magzine inherite from book
function magzine(title, auter, month, year) {
  book.call(this, title, auter, year);

  this.month = month;
}
//also prototype
magzine.prototype = Object.create(book.prototype);
magzine.prototype.constructor = magzine;

const mag1 = new magzine("HMV", "me la", "March", "1895");
console.log(mag1);
