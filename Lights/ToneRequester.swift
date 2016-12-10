//
//  ToneRequester.swift
//  Lights
//
//  Created by Pedro Sandoval on 10/15/16.
//  Copyright © 2016 Pedro Sandoval. All rights reserved.
//

import Foundation

class ToneRequester {
    
    static func requestTone(note: String) {
        var request = URLRequest(url: URL(string: "http://\(ArduinoClient.ipAddress)/&\(note)")!)
        request.httpMethod = "POST"
        let session = URLSession.shared
        
        session.dataTask(with: request) {data, response, err in
            print("\(note) tone sent.")
            }.resume()
    }
}
