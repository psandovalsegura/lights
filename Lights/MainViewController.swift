//
//  MainViewController.swift
//  Lights
//
//  Created by Pedro Sandoval on 10/15/16.
//  Copyright © 2016 Pedro Sandoval. All rights reserved.
//

import UIKit

class MainViewController: UIViewController {
    
    @IBOutlet weak var slider: UISlider!
    @IBOutlet weak var sliderLabel: UILabel!
    
    override func viewDidLoad() {
        super.viewDidLoad()

        // Do any additional setup after loading the view.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    @IBAction func redSwitch(_ sender: AnyObject) {
        var request = URLRequest(url: URL(string: "http://\(ArduinoClient.ipAddress)/$r")!)
        request.httpMethod = "GET"
        let session = URLSession.shared
        
        session.dataTask(with: request) {data, response, err in
            print("Red request sent.")
            }.resume()
    }

    @IBAction func greenSwitch(_ sender: AnyObject) {
        var request = URLRequest(url: URL(string: "http://\(ArduinoClient.ipAddress)/$g")!)
        request.httpMethod = "GET"
        let session = URLSession.shared
        
        session.dataTask(with: request) {data, response, err in
            print("Green request sent.")
            }.resume()
    }
    
    @IBAction func blueSwitch(_ sender: AnyObject) {
        var request = URLRequest(url: URL(string: "http://\(ArduinoClient.ipAddress)/$b")!)
        request.httpMethod = "GET"
        let session = URLSession.shared
        
        session.dataTask(with: request) {data, response, err in
            print("Blue request sent.")
            }.resume()
    }
    
    @IBAction func yellowSwitch(_ sender: AnyObject) {
        var request = URLRequest(url: URL(string: "http://\(ArduinoClient.ipAddress)/$y")!)
        request.httpMethod = "GET"
        let session = URLSession.shared
        
        session.dataTask(with: request) {data, response, err in
            print("Yellow request sent.")
            }.resume()
    }
    
    @IBAction func onSend(_ sender: AnyObject) {
        
    }
    
    @IBAction func onSliderValueChange(_ sender: AnyObject) {
        self.sliderLabel.text = String(self.slider.value)
    }
    
    @IBAction func tone_c(_ sender: AnyObject) {
        ToneRequester.requestTone(note: "c")
    }
    
    @IBAction func tone_d(_ sender: AnyObject) {
        ToneRequester.requestTone(note: "d")
    }
    
    @IBAction func tone_e(_ sender: AnyObject) {
        ToneRequester.requestTone(note: "e")
    }
    
    @IBAction func tone_f(_ sender: AnyObject) {
        ToneRequester.requestTone(note: "f")
    }
    
    @IBAction func tone_g(_ sender: AnyObject) {
        ToneRequester.requestTone(note: "g")
    }
    
    @IBAction func tone_a(_ sender: AnyObject) {
        ToneRequester.requestTone(note: "a")
    }
    
    @IBAction func tone_b(_ sender: AnyObject) {
        ToneRequester.requestTone(note: "b")
    }
    
    @IBAction func tone_C(_ sender: AnyObject) {
        ToneRequester.requestTone(note: "C")
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
