class Calculator {
    
    /** 
     * @param {number} value
     */
    constructor(value) {
        this.res = value;
    }
    
    /** 
     * @param {number} value
     * @return {Calculator}
     */
    add(value){
        this.res += value;
        return this; // allows chaining as the object itself is returned 
        // we didnt return "this.res" bcz (Error: 15.subtract(5) is not a function)
    }
    
    /** 
     * @param {number} value
     * @return {Calculator}
     */
    subtract(value){
        this.res -= value;
        return this; // allows chaining
    }
    
    /** 
     * @param {number} value
     * @return {Calculator}
     */  
    multiply(value) {
        this.res *= value;
        return this; // allows chaining
    }
    
    /** 
     * @param {number} value
     * @return {Calculator}
     */
    divide(value) {
        if (value === 0) {
            throw new Error("Division by zero is not allowed");
        }
        this.res /= value;
        return this;
    }
    
    /** 
     * @param {number} value
     * @return {Calculator}
     */
    power(value) {
        this.res = Math.pow(this.res, value);
        return this;
    }
    
    /** 
     * @return {number}
     */
    getResult() {
        return this.res;
    }
}
