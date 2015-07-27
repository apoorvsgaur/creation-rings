%Designed by Apoorv Gaur
function varargout = GUI6(varargin)
% GUI6 MATLAB code for GUI6.fig
%      GUI6, by itself, creates a new GUI6 or raises the existing
%      singleton*.
%
%      H = GUI6 returns the handle to a new GUI6 or the handle to
%      the existing singleton*.
%
%      GUI6('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in GUI6.M with the given input arguments.
%
%      GUI6('Property','Value',...) creates a new GUI6 or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before GUI6_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to GUI6_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help GUI6

% Last Modified by GUIDE v2.5 19-Apr-2013 12:47:12

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @GUI6_OpeningFcn, ...
                   'gui_OutputFcn',  @GUI6_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before GUI6 is made visible.
function GUI6_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to GUI6 (see VARARGIN)

% Choose default command line output for GUI6
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);
imshow('Picture_Nano.png');

% UIWAIT makes GUI6 wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = GUI6_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on button press in toLast.
function toLast_Callback(hObject, eventdata, handles)
% hObject    handle to toLast (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
close()
GUI5

% --- Executes on button press in nexSlide.
function nexSlide_Callback(hObject, eventdata, handles)
% hObject    handle to nexSlide (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in ovSlide.
function ovSlide_Callback(hObject, eventdata, handles)
% hObject    handle to ovSlide (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in homeSlide.
function homeSlide_Callback(hObject, eventdata, handles)
% hObject    handle to homeSlide (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in toHome.
function toHome_Callback(hObject, eventdata, handles)
% hObject    handle to toHome (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
close()
nanohubGUI_sec008_team24

% --- Executes on button press in toOv.
function toOv_Callback(hObject, eventdata, handles)
% hObject    handle to toOv (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
close()
overviewGUI_sec008_team24

% --- Executes on button press in toNext.
function toNext_Callback(hObject, eventdata, handles)
% hObject    handle to toNext (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
close()
GUI7

% --- Executes during object creation, after setting all properties.
function axes1_CreateFcn(hObject, eventdata, handles)
% hObject    handle to axes1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: place code in OpeningFcn to populate axes1
