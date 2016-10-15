//
//  MainViewController.swift
//  Lights
//
//  Created by Pedro Sandoval on 10/15/16.
//  Copyright © 2016 Pedro Sandoval. All rights reserved.
//

import UIKit

class MainViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()

        // Do any additional setup after loading the view.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    @IBAction func redSwitch(_ sender: AnyObject) {
        var request = URLRequest(url: URL(string: "http://134.173.60.207/$r")!)
        request.httpMethod = "GET"
        let session = URLSession.shared
        
        session.dataTask(with: request) {data, response, err in
            print("Red request sent.")
            }.resume()
    }

    @IBAction func greenSwitch(_ sender: AnyObject) {
        var request = URLRequest(url: URL(string: "http://134.173.60.207/$g")!)
        request.httpMethod = "GET"
        let session = URLSession.shared
        
        session.dataTask(with: request) {data, response, err in
            print("Green request sent.")
            }.resume()
    }
    
    @IBAction func blueSwitch(_ sender: AnyObject) {
        var request = URLRequest(url: URL(string: "http://134.173.60.207/$b")!)
        request.httpMethod = "GET"
        let session = URLSession.shared
        
        session.dataTask(with: request) {data, response, err in
            print("Blue request sent.")
            }.resume()
    }
    
    @IBAction func yellowSwitch(_ sender: AnyObject) {
        var request = URLRequest(url: URL(string: "http://134.173.60.207/$y")!)
        request.httpMethod = "GET"
        let session = URLSession.shared
        
        session.dataTask(with: request) {data, response, err in
            print("Yellow request sent.")
            }.resume()
    }
    
    
    
    /*
    // MARK: - Navigation

    // In a storyboard-based application, you will often want to do a little preparation before navigation
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        // Get the new view controller using segue.destinationViewController.
        // Pass the selected object to the new view controller.
    }
    */

}
