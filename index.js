
let count=0;

const btnInc=document.querySelector(".btn-increase");
const btnDec=document.querySelector(".btn-decrease");
const btnReset=document.querySelector(".btn-reset");
const btnSave=document.querySelector(".btn-save");
const spanId=document.getElementById("value");
const pId=document.getElementById("save");

let flag=0;

// increment the count and reflect the new to span tag using text content
btnInc.addEventListener("click",function(){
    count+=1;
    if(count>0)
    {
        spanId.style.color="green";
    }
    spanId.textContent=count;
})

// decrement the value of count by 1
btnDec.addEventListener("click",function(){
    count-=1;
    if(count<0)
    { 
        spanId.style.color = "red";
    }
    else
    {
        spanId.style.color="green";
    }
    spanId.textContent=count;
})

// Reset count value to 0 
btnReset.addEventListener("click",function(){
    count=0;
    spanId.textContent=count;
})

// save current value and display it
btnSave.addEventListener("click",function(){
    //console.log(count);

    if(flag===0)
    {
        pId.textContent="Save number are :  ";
        flag=1;
    }
     pId.textContent+=count + " - ";
})
