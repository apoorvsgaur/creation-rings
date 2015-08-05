var casper = require('casper').create();
console.log("2");
casper.start('http://google.com/', function(status){
    console.log("4.5");
    console.log("Status: " + status);
    if(status === "success"){
       page.render('indeed.png');
    }
    this.echo("I'm a Mac.")
});
console.log("3");




// page.open('https://employers.indeed.com/m#jobs?sort=date&order=desc', function(status){
//   console.log("Status: " + status);
//   if(status === "success"){
//     page.render('indeed.png');
//   }
// });
